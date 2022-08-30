#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string str;
    std::string reverseStr;
    std::cout << "Wprowadź zwrot, który ma być zamieniony" << std::endl;
    std::getline(std::cin >> std::ws, str);
    reverse(str.begin(), str.end());

    std::cout << "Zamieniony zwrot wygląda teraz tak:" << str << std::endl;
}

