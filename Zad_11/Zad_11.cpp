//a) Korzystając z implementacji BigInt i z poprzedniego zadania zaimplementuj 
// funkcje : silnia i fibonacci.
//b) Następnie zaimplementuj te metody korzystając ze standardowego long long.
//c) Porównaj dla jakich parametrów long long już nie jest w stanie wyliczyć kolejnych wartości.
//d) (Opcjonalnie) Zmierz i porównaj czas wyliczania wartości dla parametrow od 1 do wartości znalezionej w punkcie c.
//d) (Opcjonalnie) Wylicz i zmierz czas obliczania 90!


#include <iostream>
#include "BigIntClass.h"
#include <chrono>


template<typename T>
T findFib(int n)
{
    T a = 0;
    T b = 1;
    T sum = 0;

    for (size_t i = 1; i < n; ++i)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}

template<typename T>
T findFactorial(int n)
{
    T result = 1;
    for (size_t i = 1; i <= n; ++i)
    {
        result = result * i;
    }
    return result;
}

int main()
{
    std::cout << "Fibonacci 100=" << findFib<BigInt>(100).toString() << std::endl;
    std::cout << "Silnia 21=" << findFactorial<BigInt>(21).toString() << std::endl;
  
    int i = 0;
    do
    {
        ++i;
        std::cout << "Fibonacci "<< i << " = " << findFib<long long int>(i) << std::endl;
        
    } while (findFib<BigInt>(i) == findFib<long long int>(i));

    i = 0;
    do
    {
        ++i;
        std::cout << "Silnia " << i << " = " << findFactorial<long long int>(i) << std::endl;

    } while (findFactorial<BigInt>(i) == findFactorial<long long int>(i));

    i = 0;
    do
    {
        ++i;
        auto start = std::chrono::steady_clock::now();
        std::cout << "Fibonacci " << i << " = " << findFib<long long int>(i) << std::endl;
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << "Wyliczenie tego zajelo " << elapsed.count() << "ms" << std::endl << std::endl;
    } while (i<92);
    i = 0;
    do
    {
        ++i;
        auto start = std::chrono::steady_clock::now();
        std::cout << "Silnia " << i << " = " << findFactorial<long long int>(i) << std::endl;
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << "Wyliczenie tego zajelo " << elapsed.count() << "ms" << std::endl << std::endl;
    } while (i < 20);

    auto start = std::chrono::steady_clock::now();
    std::cout << "Fibonacci 90=" << findFib<BigInt>(90).toString() << std::endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Wyliczenie tego zajelo " << elapsed.count() << "ms" << std::endl << std::endl;
    
    start = std::chrono::steady_clock::now();
    std::cout << "Silnia 90=" << findFactorial<BigInt>(90).toString() << std::endl;
    end = std::chrono::steady_clock::now();
    elapsed = end - start;
    std::cout << "Wyliczenie tego zajelo " << elapsed.count() << "ms" << std::endl << std::endl;
}

