// Stwórz listę liczb od 1 do 1000. 
// Rozdziel te liczby na dwie osobne listy: liczby pierwsze i nie liczby pierwsze. 

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool ifPrimeNum(int n)
{
    if (n < 2)
    {
        return false;
    }
        
    for (int i = 2; i * i <= n; ++i)
    {
        if (n%i == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

int main()
{
    std::vector<int>list(1000);
    std::vector<int>primeNum;
    std::vector<int>notPrimeNum;
    std::iota(list.begin(), list.end(), 1);
    std::cout << "Stworzony wektor: " << std::endl << std::endl;
    std::for_each(list.begin(), list.end(), [](const int i) {std::cout << i << "; "; });
    std::cout << std::endl << std::endl;
    std::for_each(list.begin(), list.end(), [&primeNum, &notPrimeNum](const int i) {
        if (ifPrimeNum(i))
        {
            primeNum.push_back(i);
        }
        else
        {
            notPrimeNum.push_back(i);
        }});

    std::cout << "Liczby pierwsze z zakresu 1-1000: " << std::endl << std::endl;
    std::for_each(primeNum.begin(), primeNum.end(), [](const int i) {std::cout << i << "; "; });
    std::cout<<std::endl << std::endl;
    std::cout << "Pozostałe liczby z zakresu 1-1000: " << std::endl << std::endl;
    std::for_each(notPrimeNum.begin(), notPrimeNum.end(), [](const int i) {std::cout << i << "; "; });
}

