#include "RectangleClass.hpp"

Rectangle::Rectangle(unsigned int a, unsigned int b)
	: _a(a), _b(b)
{
}

Rectangle::~Rectangle()
{
}

bool Rectangle::isSquare()const
{
	return _a==_b;
}

unsigned int Rectangle::getArea()const
{
	return _a*_b;
}

int Rectangle::getA()
{
	return _a;
}

int Rectangle::getB()
{
	return _b;
}
