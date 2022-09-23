//Napisz program, który wypisze najbardziej optymalny schemat wydawania reszty dla podanej kwoty.
//(nominały: 200, 100, 50, 20, 10, 5, 2, 1, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01)

#include <iostream>
#include <iomanip>

void calcualteNominalsToSpent(int value, int tab[15])
{
    for (size_t i = 0; value>0; ++i)
    {
        int nominalsQty = value / tab[i];
        if (nominalsQty > 0)
        {
            if (tab[i] >= 100)
                std::cout << std::setw(3) << tab[i] / 100 << " zł ";
            else
            {
                std::cout << std::setw(3) << tab[i] << " gr ";
            }
            std::cout << nominalsQty << std::endl;
            value %= tab[i];
        }
    }
}
int main()
{
    int tab[] = { 50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    double rest;
    std::cout << "Reszta do wydania: ";
    std::cin >> rest;
    std::cout << "----------------------------\n";
    int value = int(rest * 100);
    calcualteNominalsToSpent(value, tab);
    std::cout << "----------------------------\n";
}

