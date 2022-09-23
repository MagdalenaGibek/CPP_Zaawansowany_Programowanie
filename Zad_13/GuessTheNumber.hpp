#pragma once
#include <random>
#include <iostream>

class GuessTheNumber
{
public:
	GuessTheNumber();
	virtual ~GuessTheNumber()=default;
	int getNumber();
	bool isGuessed(int guess);

private:
	int _theNumber;

};