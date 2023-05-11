



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
    //������������� ������� Key and Initialization vector  
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
  
    // ������ �����
   
    cout << "������� ��� ����� � ����� ������� ��� ������������� ����������:";
    cin >> filename;

    ifstream in(filename); // �������� ���� ��� ������
    if (in.is_open())
    {
        while (getline(in, text))
        {
            cout << text << endl;
        }
    }
    in.close();     // ��������� ����

    cout << "������ ������ �� ����� (" << text.size() << " ����)" << endl;
    cout << endl << endl;

    
    // ������� �����
  
    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);

    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));//��������� ���������� �� ���� �������������. 
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(text.c_str()), text.length());//ECB � ����� CBC ������ ���� ��������� �� ������� ����� �����.
    stfEncryptor.MessageEnd();

   cout << "������ �������������� ������(" << ciphertext.size() << " ����)" << endl;

    for (int i = 0; i < ciphertext.size(); i++) {

        cout << "0x" << hex << (0xFF & static_cast<CryptoPP::byte>(ciphertext[i])) << " ";
    }
   
    //������� ������������� ����� � ����
    ofstream out;          // ����� ��� ������
    out.open("SimCipher.txt");      // ��������� ���� ��� ������
    if (out.is_open())
    {
        for (int i = 0; i < ciphertext.size(); i++) {
            
         out << "0x" << hex << (0xFF & static_cast<CryptoPP::byte>(ciphertext[i])) << " ";
        }
    }
    out.close();
    cout << endl;  
    std::cout << "������������� ����� ��� �������" << std::endl;
    cout << endl << endl;

  
    // ��������������   
    cout << "������� ��� ����� � ����� ������� ��� ���������������:";
    cin >> filename;

    string ciphertextfromfile;

    ifstream inciph(filename); // �������� ���� ��� ������
    if (inciph.is_open())
    {
        cout << "��������� �����:" << endl;
        while (getline(inciph, ciphertextfromfile))
        {
            cout << ciphertextfromfile << endl;
        }

    }
    inciph.close();     // ��������� ����
    cout << endl;
   

   // cout << "��������� �����:" << endl << ciphertextfromfile  << endl;
    cout << "������ �������������� ������(" << ciphertextfromfile.size() << " ����)" << endl << endl;//������-�� �� ����� ������ ����� � ������ ������� ������

    

    CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);

    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedtext));
  //  stfDecryptor.Put(reinterpret_cast<const unsigned char*>(ciphertextfromfile.c_str()), ciphertextfromfile.size());
    stfDecryptor.Put(reinterpret_cast<const unsigned char*>(ciphertext.c_str()), ciphertext.size());
    stfDecryptor.MessageEnd();

   
    cout << "�������������� �����: " << endl;
    cout << decryptedtext;
    cout << endl << endl;


    return 0;
}