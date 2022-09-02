#include "RectangleMangerClass.hpp"
#include<iostream>
#include<algorithm>
#include<utility>

void printElement(Rectangle r) 
{
	printElementToStream(std::cout, r);
}

void printElementToStream(std::ostream& str, Rectangle r)
{
	str << r.getA() << std::endl;
	str << r.getB() << std::endl;
	str << std::endl;
}

RectangleManger::RectangleManger(unsigned int howMany, unsigned int sizeFrom, unsigned int sizeTo)
	: _howMany(howMany)
{
	RectangleGenerator rectGen(sizeFrom, sizeTo);

	for (size_t i = 0; i < howMany; ++i)
	{
		rectangles.push_back(rectGen.generate());
	}
}

size_t RectangleManger::countRectangleBiggerThen(int area)
{
	auto counter = std::count_if(rectangles.begin(), rectangles.end(), [area](Rectangle r) {return r.getArea() > area; });
	return counter;
}

std::vector<Rectangle> RectangleManger::copyRectangles()
{
	std::vector<Rectangle>squares;
	std::copy_if(rectangles.begin(), rectangles.end(), std::back_inserter(squares), [&squares](Rectangle r) {
		return r.isSquare(); });

	//std::for_each(squares.begin(), squares.end(), printElement);

	return squares;
}

void RectangleManger::sortAreaDescending()
{
	std::sort(rectangles.begin(), rectangles.end(), [](Rectangle r1, Rectangle r2) {
		return r1.getArea() > r2.getArea(); });
}

void RectangleManger::deleteInvalid()
{
	rectangles.erase(std::remove_if(rectangles.begin(), rectangles.end(), [](Rectangle r) {
		return (r.getA() == 0 || r.getB() == 0);
	}), rectangles.end());
}

void RectangleManger::printRectangles()
{
	std::for_each(rectangles.begin(), rectangles.end(), printElement);
}

std::ostream& operator<<(std::ostream& str, const std::vector<Rectangle>& vector)
{
	std::for_each(vector.begin(), vector.end(), [&str](Rectangle r) {
		printElementToStream(str, r);
	});
	
	return str;
}