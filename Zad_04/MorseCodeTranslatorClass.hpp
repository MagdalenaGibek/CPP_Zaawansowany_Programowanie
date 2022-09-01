//Napisz klasę, która umożliwi kodowanie i dekodowanie stringa na alfabet Morsea.Ignorujemy znaki specjalne(znak rodzielający)
//KlasaMorseCodeTranslator
//toMorseCode
//fromMorseCode

#pragma once
#include <string>
#include <map>
class MorseCodeTranslator
{
public:
	MorseCodeTranslator();
	virtual ~MorseCodeTranslator();
	std::string toMorseCode(std::string text);
	std::string fromMorseCode(std::string text);
private:
    std::map<char, std::string>morseDictionary{ {'A',".-"},{'B',"- ..."},{'C',"-.-."},
		{'D',"-.."},{'E',"."},{'F',"..-."},{'G',"--."},{'H',"...."},{'I',".."},
		{'J',".---"} ,{'K',"-.-"}, {'L',".-.."},{'M',"--"},{'N',"-."}, {'O',"---"},
		{'P',".--."},{'Q',"--.-"},{'R',".-."},{'S',"..."},{'T',"-"}, {'U',"..-"},
		{'V',"...-"},{'W',".--"},{'X',"-..-"},{'Y',"-.--"} ,{'Z',"--.."}, {'1',".----"},
		{'2',"..---"},{'3',"...--"},{'4',"....-"}, {'5',"....."} ,{'6',"-...."},{'7',"--..."},
		{'8',"---.."}, {'9',"----."} ,{'0',"-----"} };

	std::map<std::string, char>latinDictionary{ {".-",'A'},{"- ...",'B'},{"-.-.",'C'},
	{"-..",'D'},{".",'E'},{"..-.",'F'},{"--.",'G'},{"....",'H'},{"..",'I'},
	{".---",'J'} ,{"-.-",'K'}, {".-..",'L'},{"--",'M'},{"-.",'N'}, {"---",'O'},
	{".--.",'P'},{"--.-",'Q'},{".-.",'R'},{"...",'S'},{"-",'T'}, {"..-",'U'},
	{"...-",'V'},{".--",'W'},{"-..-",'X'},{"-.--",'Y'} ,{"--..",'Z'}, {".----",'1'},
	{"..---",'2'},{"...--",'3'},{"....-",'4'}, {".....",'5'} ,{"-....",'6'},{"--...",'7'},
	{"---..",'8'}, {"----.",'9'} ,{"-----",'0'} };
};