#include "MorseCodeTranslatorClass.hpp"
#include <map>
#include <string>

MorseCodeTranslator::MorseCodeTranslator()
{
}

MorseCodeTranslator::~MorseCodeTranslator()
{
}
std::string MorseCodeTranslator::toMorseCode(std::string text)
{
    std::string translated;

    for (auto it = text.begin(); it != text.end(); ++it)
    {
        if (*it >= 'a' && *it <= 'z')
        {
            auto c = std::toupper(*it);
            translated += morseDictionary.at(c);
            translated += " ";
        }
        else if (*it >= '0' && *it <= '9' || *it >= 'A' && *it <= 'Z')
        {
            translated += morseDictionary.at(*it);
            translated += " ";
        }
    }
    return translated;
}

std::string MorseCodeTranslator::fromMorseCode(std::string text)
{
    std::string translated;
    std::string tmp;

    for (auto it = text.begin(); it != text.end(); ++it)
    {
        if (*it == ' ')
        {
            translated += latinDictionary.at(tmp);
            tmp = "";
        }
        else
        {
            tmp += *it;
        }
    }

    if (tmp != "")
    {
        translated += latinDictionary.at(tmp);
        tmp = "";
    }
    return translated;
}
