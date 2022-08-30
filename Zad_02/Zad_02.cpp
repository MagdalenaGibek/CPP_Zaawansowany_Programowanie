// Napisz funkcję, która przyjmie dwa stringi i zwróci ile liter mają wspólnych.

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

int numOfLetters(std::string str1, std::string str2)
{
    std::set<char>text1;
    std::set<char>text2;
    for (std::string::iterator itStr = str1.begin(); itStr != str1.end(); itStr++)
    {
        if (*itStr >= 65 && *itStr <= 90)
        {
            *itStr += 32;
        }

        if (*itStr >= 97 && *itStr <= 122)
        {
            text1.insert(*itStr);
        }
    }

    for (std::string::iterator itStr = str2.begin(); itStr != str2.end(); itStr++)
    {
        if (*itStr >= 65 && *itStr <= 90)
        {
            *itStr += 32;
        }

        if (*itStr >= 97 && *itStr <= 122)
        {
            text2.insert(*itStr);
        }
    }

    int counter = 0;

    for (auto itSet = text1.begin(); itSet != text1.end(); itSet++)
    {
        auto search = text2.find(*itSet);
        if (search != text2.end())
        {
            ++counter;
        }
        
    }

    return counter;

}

int main()
{
    std::cout <<"Kasia i Basia mają " << numOfLetters("Kasia", "Basia")<<" litery wspólne"<<std::endl;
    std::cout << "Marek i Magda mają " << numOfLetters("Marek", "Magda") << " litery wspólne" << std::endl;
    std::cout << "Sraty Taty i Majtki w Kraty mają " << numOfLetters("Sraty Taty", "Majtki w Kraty") << " litery wspólne" << std::endl;
}
