//Napisz gre w zgadywanie numeru.Program losuje liczbe z przedziału 1 - 100, a uzytkownik proboje zgadnąć.
//Po kazdej próbie program podpowiada czy liczba jest większa czy mniejsza od podanej przez gracza.Gdy, gracz jest
//blisko(np + -3) to program powinien dodatkowo powiadomić gracza o tym, że jest blisko.
//Zadanie można rozwiązac za pomocą jednej klasy GuessTheNumber

#include <iostream>
#include"GuessTheNumber.hpp"
int main()
{
    GuessTheNumber number;
    std::cout << "Witaj w grze jaka to liczba." << std::endl;
    std::cout << "Mam na myśli pewną liczbę z zakresu od 1 do 100." << std::endl;
    std::cout << "Spróbuj ją odgadną z najmniejszej liczbie prób." << std::endl;
    int guess = 0;
    std::cout << "Ta liczba to: " << std::endl;

    bool result = false;
    std::cin >> guess;
    do
    {
        result = number.isGuessed(guess);
        std::cin >> guess;

    } while (result != true);

}

