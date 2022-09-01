//Klasa: StringCensor
//Napisz klasę która będzie cenzurować podane stringi(zamieniać wymagane litery na gwiazkę), operacje która ma wspierać ta klasa :
//-addCensoredLetter(char c)
//- std::string censor(std::string)

#pragma once
#include<string>
#include<set>

class StringCensor
{
public:
	StringCensor();
	virtual~StringCensor();
	void addCensoredLetter(char c);
	std::string censor(std::string text) const;
private:
	const char censorChar = '*';
	std::set<char>censoredLetter;
};