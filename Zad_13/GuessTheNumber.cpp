#include "GuessTheNumber.hpp"

GuessTheNumber::GuessTheNumber()
{
	std::random_device r;
	std::default_random_engine defEngine(r());
	std::uniform_int_distribution<int> intDistro(1, 100);
	_theNumber = intDistro(defEngine);
}

int GuessTheNumber::getNumber()
{
	return _theNumber;
}

bool GuessTheNumber::isGuessed(int guess)
{
    bool result = false;
    if ((guess + 3) == _theNumber || (guess - 3) == _theNumber)
    {
        std::cout << "Jesteś blisko..." << std::endl;
    }
    else if (guess > _theNumber)
    {
        std::cout << "Za duża..." << std::endl;
    }
    else if (guess < _theNumber)
    {
        std::cout << "Za mała..." << std::endl;
    }
    else if (_theNumber == guess)
    {
        std::cout << "Odgadłeś! Ta liczba to: " << _theNumber << std::endl;
        result = true;
    }
	return result;
}

