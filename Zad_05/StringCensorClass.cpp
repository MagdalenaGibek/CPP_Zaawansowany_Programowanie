#include "StringCensorClass.hpp"

StringCensor::StringCensor()
{
}

StringCensor::~StringCensor()
{
}

void StringCensor::addCensoredLetter(char c)
{
	censoredLetter.insert(std::tolower(c));
}

std::string StringCensor::censor(std::string text) const
{
	std::string conseredStr;
	for (auto it = text.begin(); it != text.end(); ++it)
	{
		auto search = censoredLetter.find(std::tolower(*it));

		if (search != censoredLetter.end())
		{
			conseredStr += '*';
		}
		else
		{
			conseredStr += *it;
		}
	}
	return conseredStr;
}
