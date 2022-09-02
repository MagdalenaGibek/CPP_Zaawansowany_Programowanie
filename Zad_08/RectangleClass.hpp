#pragma once

class Rectangle
{
public:
	Rectangle(unsigned int a, unsigned int b);
	virtual~Rectangle();
	bool isSquare() const;
	unsigned int getArea() const;
	int getA();
	int getB();
private:
	unsigned int _a;
	unsigned int _b;
};
