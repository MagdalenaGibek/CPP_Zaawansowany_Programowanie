#include <iostream>
#include "CaesarCipherClass.hpp"

int main()
{
    CaesarCipher str;
    std::string encryptedStr = str.cypher("Ala ma kota", 5);
    std::cout << encryptedStr << std::endl;
    std::cout << str.decepher(encryptedStr, 5) << std::endl;
}

