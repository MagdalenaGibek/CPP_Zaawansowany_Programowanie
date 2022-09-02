#pragma once
#include "RectangleGeneratorClass.hpp"
#include <vector>
#include <iostream>

void printElement(Rectangle r);
void printElementToStream(std::ostream& str, Rectangle r);

class RectangleManger
{
public:
	RectangleManger(unsigned int howMany, unsigned int sizeFrom, unsigned int sizeTo);
	void printRectangles();
	size_t countRectangleBiggerThen(int area);
	std::vector <Rectangle> copyRectangles(); // do tego muszę dorobić operator wypisywania
	void sortAreaDescending();
	void deleteInvalid();

protected:
	std::vector<Rectangle> rectangles;
	int _howMany;
};

std::ostream& operator<<(std::ostream& str, const std::vector<Rectangle>& r);
