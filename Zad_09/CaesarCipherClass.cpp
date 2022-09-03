#include "CaesarCipherClass.hpp"

CaesarCipher::CaesarCipher()
	
{
}

CaesarCipher::~CaesarCipher()
{
}

std::string CaesarCipher::cypher(std::string text, int secretValue)
{
	std::string encrypted;
	for (auto it = text.begin(); it != text.end(); ++it)
	{
		if (*it >= 'A' && *it <= 'Z')
		{
			encrypted +=(*it - 'A' + secretValue) % numOfLetters + 'A';
		}
		else if(*it >= 'a' && *it <= 'z')
		{
			encrypted +=(*it - 'a' + secretValue) % numOfLetters + 'a';
		}
		else if (*it == ' ')
		{
			encrypted += ' ';
		}
	}
	return encrypted;
}

std::string CaesarCipher::decepher(std::string text, int secretValue)
{
	std::string decrypted;
	for (auto it = text.begin(); it != text.end(); ++it)
	{
		if (*it >= 'A' && *it <= 'Z')
		{
			decrypted += (*it - 'A' - secretValue) % numOfLetters + 'A';
		}
		else if (*it >= 'a' && *it <= 'z')
		{
			decrypted +=(*it - 'a' - secretValue) % numOfLetters + 'a';
		}
		else if (*it == ' ')
		{
			decrypted +=' ';
		}
	}
	return decrypted;
}
