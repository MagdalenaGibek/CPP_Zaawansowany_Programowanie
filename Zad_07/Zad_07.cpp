// Stworz listę 50 liczb całkowitych dodatnich i wypełnij ją losowymi wartościami. 
// Wypisz ją.
// Następnie posortuj i wypisz listę tak, by na początku znalazły się wartości parzyste uporządkowane rosnąco, a za nimi wartości nieparzyste uporządkowane malejąco.
// Podpowiedz: Podziel listę na dwie osobne, odpowiednio posortuj, a następnie ja połącz w jedną.


#include <iostream>
#include <vector>
#include <random>
#include <functional>


int main()
{
    std::vector<unsigned int>listNum(50);
    std::vector<unsigned int>evenNum;
    std::vector<unsigned int>unevenNum;
    std::vector<unsigned int>sortedList;
 

    std::random_device r;
    std::default_random_engine defEngine(r());
    std::uniform_int_distribution<int> intDistro(0, 1000);
    for (auto it = listNum.begin(); it != listNum.end(); it++)
    {
        *it = intDistro(defEngine);
    }

    std::cout << "Stworzony wektor:" << std::endl << std::endl;
    std::for_each(listNum.begin(), listNum.end(), [](unsigned int i) {std::cout << i << "; "; });
    std::cout << std::endl << std::endl;
    std::for_each(listNum.begin(), listNum.end(), [&evenNum, &unevenNum](unsigned int i) {
        if (i % 2 == 0)
        {
            evenNum.push_back(i);
        }
        else
        {
            unevenNum.push_back(i);
        }
        });

    std::cout << "Liczby parzyste:" << std::endl << std::endl;
    std::for_each(evenNum.begin(), evenNum.end(), [](unsigned int i) {std::cout << i << "; "; });
    std::cout << std::endl << std::endl;
    std::cout << "Liczby nieparzyste:" << std::endl << std::endl;
    std::for_each(unevenNum.begin(), unevenNum.end(), [](unsigned int i) {std::cout << i << "; "; });
    std::cout << std::endl << std::endl;

    std::sort(evenNum.begin(), evenNum.end());
    std::sort(unevenNum.begin(), unevenNum.end(), std::greater<int>());
   
    listNum.clear();
    sortedList.resize(evenNum.size() + unevenNum.size());
    std::move(evenNum.begin(), evenNum.end(), sortedList.begin());
    std::move(unevenNum.begin(), unevenNum.end(), sortedList.begin()+evenNum.size());
    evenNum.clear();
    unevenNum.clear();

    std::cout << "Posortowana lista:" << std::endl << std::endl;
    std::for_each(sortedList.begin(), sortedList.end(), [](unsigned int i) {std::cout << i << "; "; });
    
}
  

