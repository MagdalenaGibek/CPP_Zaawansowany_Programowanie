//Klasy: Rectangle(przechowuje długości boków, wylicza pole, isSquare()), RectangleGenerator(Klasa genreująca losowy prostokąt o boku z podanego przedziału), RectangleManger(tutaj faktycznie implementujemy zadania)
//Utwórz wektor 100 prostokątów o losowych długościach boków z przedziału 0, 10 (użyj liczb całkowitych)
//a) void printRectangles() - Wypisz wszystkie prostokąty(for_each + unary function)
//b) size_t countRectangleBiggerThen(int area) - Wypisz ile jest prostokątów o polu większym niż 50 (count_if)
//c) std::vector copyRectangles() - Przekopiuj wszystkie prostkąty, które są kwadratami do drugiego vectora(copy_if) i go wypisz(for_each)
//d) void sortAreaDescending() - Posortuj vector prostokątów malejaco według pola powierzchni
//e) void deleteInvalid() Usuń wszystkie prostokąty, które mają przynajmniej jeden bok równy 0
#include <iostream>
#include<algorithm>
#include<utility>
#include "RectangleClass.hpp"
#include "RectangleGeneratorClass.hpp"
#include "RectangleMangerClass.hpp"

int main()
{
    RectangleManger rects(100,0,10);
    rects.printRectangles();
    rects.deleteInvalid();
    std::cout << "Lista prostokątów: " << std::endl;
    rects.printRectangles();
    int rectanglesBiggerThan = 50;
    std::cout<<"Liczba prostokątów, którzych pole jest większe niż " << rectanglesBiggerThan <<" : " << rects.countRectangleBiggerThen(rectanglesBiggerThan) << std::endl;
    std::cout << "Lista kwadratów zawartych w zbiorze prostokątów: " << rects.copyRectangles()<<std::endl;
    
    //auto squares = rects.copyRectangles();
    //std::for_each(squares.begin(), squares.end(), printElement);
    
    rects.sortAreaDescending();
    std::cout << "Wszystkie prostokąty posortowane malejąco według pola: " << std::endl;
    rects.printRectangles();
 
}
