#pragma once
#include "RectangleClass.hpp"

class RectangleGenerator
{
public:
	RectangleGenerator(unsigned int sizeFrom, unsigned int sizeTo);
	Rectangle generate();
private:
	unsigned int _sizeFrom;
	unsigned int _sizeTo;
};