#include <windows.h>
#include <wincrypt.h>
#include <iostream>
#include <fstream>
#pragma once
using namespace std;
class Crypt 
{
HCRYPTPROV hProv;
HCRYPTKEY hKey;
public:
    Crypt(const char* key) {
        HCRYPTHASH hHash;
        // Создаем контекст для шифрования
        if (!CryptAcquireContextW(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT))
        {
            std::cout << "CryptAcquireContext" << std::endl;
            exit(1);
        }
        // Создаем хэш
        if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash))
        {
            std::cout << "CryptCreateHash";
            exit(2);
        }
        // Хэшируем пароль - это будет ключ
        if (!CryptHashData(hHash, (BYTE*)key, strlen(key), 0)) {
            std::cout << "CryptHashData Failed";
            exit(3);
        }
        // Применяем ключ
        if (!CryptDeriveKey(hProv, CALG_AES_128, hHash, 0, &hKey)) {
            std::cout << "CryptDeriveKey failed";
            exit(4);
        }
    }
    ~Crypt() {
        CryptReleaseContext(hProv, 0);
    }
    void save(std::string buffer, std::ostream& file) {
        DWORD length = buffer.size();
        BYTE* buff = new BYTE[length + 16];
        memcpy(buff, buffer.c_str(), length);
        if (!CryptEncrypt(hKey, NULL, TRUE, 0, buff, &length, length+16))
        {
            std::cout << "Ошибка шифрования\n";
            exit(5);
        }
        file.write((const char*)buff, length);
        delete [] buff;
    }
    std::string decrypt(ifstream& inFlow){
        long pos = inFlow.tellg();
        inFlow.seekg(0, ios::end);
        DWORD length = inFlow.tellg();
        inFlow.seekg(pos, ios::beg);
        BYTE* buff = new BYTE[length + 16];
        inFlow.read((char*)buff, length);
        if (!CryptDecrypt(hKey, NULL, TRUE, 0, buff, &length))
        {
            std::cout << "Ошибка расшифровки";
            exit(6);
        }
        std::string result((const char*)buff, length);
        delete[] buff;
        return(result);
    }
};