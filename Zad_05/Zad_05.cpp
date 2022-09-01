#include"StringCensorClass.hpp"
#include <iostream>

int main()
{
    StringCensor text;
    text.addCensoredLetter('a');
    text.addCensoredLetter('j');
    std::cout << "Ocenzurowany łańcuch: " << text.censor("Jedziemy na wakacje.");
}


