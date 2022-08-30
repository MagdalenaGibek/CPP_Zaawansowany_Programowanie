#include <iostream>
#include <string>
#include <algorithm>

std::string reverseStr(std::string str)
{
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    std::string strToReverse;
    std::cout << "Wprowadź zwrot, który ma być zamieniony" << std::endl;
    std::getline(std::cin >> std::ws, strToReverse);
    std::cout << "Zamieniony zwrot wygląda teraz tak:" << reverseStr(strToReverse) << std::endl;
}

