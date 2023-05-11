// BotanRSA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <botan/auto_rng.h>
#include <botan/p11.h>
#include <botan/p11_rsa.h>
#include <botan/p11_types.h>
#include <botan/pubkey.h>
#include <botan/rsa.h>
#include <botan/hex.h>
#include <botan/pkcs8.h>
#include <botan/data_src.h>

#include <botan/botan.h>


#include <vector>


using namespace std;

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "Russian");


    // Вводим текст
    string filename, text;
    cout << "Введите имя файла в папке проекта для Асимметричного шифрования:";
    cin >> filename;

    ifstream inRSA(filename); // окрываем файл для чтения
    if (inRSA.is_open())
    {
        while (getline(inRSA, text))
        {
            cout << text << endl;
        }
    }
    inRSA.close();     // закрываем файл

    cout << "Размер текста из файла (" << text.size() << " байт)" << endl;
    cout << endl << endl;




    // create private key in software
    Botan::AutoSeeded_RNG rng;//Random Number Generator
    Botan::RSA_PrivateKey priv_key_sw(rng, 2048);//A constructor that creates a new random RSA private key with a modulus of length bits.
    vector<uint8_t> pt(text.data(), text.data() + text.length());
   

    cout << "text=";
    for (auto symb : pt) cout << symb;
    cout << endl;
    cout << "PT=" << Botan::hex_encode(pt) << endl;

    string pub = Botan::X509::PEM_encode(priv_key_sw);
    string priv = Botan::PKCS8::PEM_encode(priv_key_sw);
    cout << "pub" << pub << endl;
    cout << "priv" << priv << endl;


    // load keypair
    Botan::DataSource_Memory key_pub(pub);
    Botan::DataSource_Memory key_priv(priv);
 

    Botan::X509_PublicKey* pub_rsa = Botan::X509::load_key(key_pub);
    Botan::PKCS8_PrivateKey* priv_rsa = Botan::PKCS8::load_key(key_priv, rng);
  


    // шифрование открытым ключом
    Botan::PK_Encryptor_EME enc(*pub_rsa, rng, "OAEP(SHA-256)");
    std::vector<uint8_t> ciphertext = enc.encrypt(pt, rng);
   

    ofstream out;          // поток для записи
    out.open("AsimCipher.txt");      // открываем файл для записи
    if (out.is_open())
    {
        out << Botan::hex_encode(ciphertext) << endl;
    }
    out.close();
    cout << "Файл был записан" << endl;



    //Считываем из файла зашифрованный текст
    cout << "Введите имя файла в папке проекта для Асимметричного расшифровывания:";
    cin >> filename;
    string ciphertextfromfile;

    ifstream inRSAciph(filename); // окрываем файл для чтения
    if (inRSAciph.is_open())
    {
        while (getline(inRSAciph, ciphertextfromfile))
        {
            cout << ciphertextfromfile << endl;
        }
    }
    inRSAciph.close();     // закрываем файл

    cout << "Размер текста из файла (" << ciphertextfromfile.size() << " байт)" << endl;//почему-то не пишет размер файла и дальше тянется ошибка
    cout << endl << endl;

    //преобразуем текст в вектор
    vector<uint8_t> ciphertext2(ciphertextfromfile.data(), ciphertextfromfile.data() + ciphertextfromfile.length());




    // расшифрование закрытым ключом
    Botan::PK_Decryptor_EME dec(*priv_rsa, rng, "OAEP(SHA-256)");
    Botan::secure_vector<uint8_t> decrypted = dec.decrypt(ciphertext);
    //Botan::secure_vector<uint8_t> decrypted = dec.decrypt(ciphertext2);
        cout << endl
        << "enc: " << Botan::hex_encode(ciphertext) << endl
        << "dec: " << Botan::hex_encode(decrypted);


    cout << endl << "Расшифрованный text=";
    for (auto symb2 : decrypted) std::cout << symb2;
    // стандарт шифрования OAEP с хэш-алгоритмом SHA256.
 //PKCS #8 является стандартным синтаксисом для хранения информации о секретном ключ
 //цифровой сертификат X509 представляют собой открытый ассиметричный ключ
    return 0;

}
