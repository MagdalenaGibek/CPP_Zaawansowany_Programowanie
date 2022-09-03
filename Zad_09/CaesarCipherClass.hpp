#pragma once
#include<string>
class CaesarCipher
{
public:
	CaesarCipher();
	virtual~CaesarCipher();
	std::string cypher(std::string text, int secretValue);
	std::string decepher(std::string text, int secretValue);
private:
	int numOfLetters = 26;
};