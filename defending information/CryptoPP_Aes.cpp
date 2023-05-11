



#include <typeinfo>
#include <iostream>
#include <fstream>
#include <iomanip>

#include <cryptopp/rijndael.h>
#include "cryptopp/modes.h"
#include "cryptopp/aes.h"
#include "cryptopp/filters.h"
#include "cryptopp/osrng.h"




using namespace std;

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "Russian");
  
    //Crypto++, AES
    // 
    //Устанавливаем размеры Key and Initialization vector  
    //DEFAULT_KEYLENGTH= 16 bytes
    CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];

    CryptoPP::AutoSeededRandomPool prng;
    prng.GenerateBlock(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    prng.GenerateBlock(iv, CryptoPP::AES::BLOCKSIZE);
 
    cout << "key=" << key << endl << "IV=" << iv << endl;

   
    string text;
    string ciphertext;
    string decryptedtext;
    string filename;
  
    // Вводим текст
   
    cout << "Введите имя файла в папке проекта для Симметричного шифрования:";
    cin >> filename;

    ifstream in(filename); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, text))
        {
            cout << text << endl;
        }
    }
    in.close();     // закрываем файл

    cout << "Размер текста из файла (" << text.size() << " байт)" << endl;
    cout << endl << endl;

    
    // Шифруем текст
  
    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);

    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));//добавляет заполнение по мере необходимости. 
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(text.c_str()), text.length());//ECB и режим CBC должны быть дополнены до размера блока шифра.
    stfEncryptor.MessageEnd();

   cout << "Размер зашифрованного текста(" << ciphertext.size() << " байт)" << endl;

    for (int i = 0; i < ciphertext.size(); i++) {

        cout << "0x" << hex << (0xFF & static_cast<CryptoPP::byte>(ciphertext[i])) << " ";
    }
   
    //выводим зашифрованный текст в файл
    ofstream out;          // поток для записи
    out.open("SimCipher.txt");      // открываем файл для записи
    if (out.is_open())
    {
        for (int i = 0; i < ciphertext.size(); i++) {
            
         out << "0x" << hex << (0xFF & static_cast<CryptoPP::byte>(ciphertext[i])) << " ";
        }
    }
    out.close();
    cout << endl;  
    std::cout << "Зашифрованный текст был записан" << std::endl;
    cout << endl << endl;

  
    // Расшифровываем   
    cout << "Введите имя файла в папке проекта для расшифровывания:";
    cin >> filename;

    string ciphertextfromfile;

    ifstream inciph(filename); // окрываем файл для чтения
    if (inciph.is_open())
    {
        cout << "Считанный текст:" << endl;
        while (getline(inciph, ciphertextfromfile))
        {
            cout << ciphertextfromfile << endl;
        }

    }
    inciph.close();     // закрываем файл
    cout << endl;
   

   // cout << "Считанный текст:" << endl << ciphertextfromfile  << endl;
    cout << "Размер зашифрованного текста(" << ciphertextfromfile.size() << " байт)" << endl << endl;//почему-то не пишет размер файла и дальше тянется ошибка

    

    CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);

    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedtext));
  //  stfDecryptor.Put(reinterpret_cast<const unsigned char*>(ciphertextfromfile.c_str()), ciphertextfromfile.size());
    stfDecryptor.Put(reinterpret_cast<const unsigned char*>(ciphertext.c_str()), ciphertext.size());
    stfDecryptor.MessageEnd();

   
    cout << "Расшифрованный текст: " << endl;
    cout << decryptedtext;
    cout << endl << endl;


    return 0;
}