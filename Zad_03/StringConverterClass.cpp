#include "StringConverterClass.hpp"

StringConverter::StringConverter()
{
}

StringConverter::~StringConverter()
{
}

std::string StringConverter::toCamelCase(std::string str)
{
	std::string finalStr;
	
	for (auto itr = str.begin(); itr!=str.end(); ++itr)
	{
		if (*itr >= 65 && *itr <= 90)
		{
			finalStr += '_';
			finalStr += *itr + 32;
		}
		else
		{
			finalStr += *itr;
		}
	}
	return finalStr;
}

std::string StringConverter::toSnakeCase(std::string str)
{
	std::string finalStr;
	bool makeUpper = false;

	for (auto itr = str.begin(); itr != str.end(); ++itr)
	{
		if (*itr == 95)
		{
			makeUpper = true;
		}
		else if (makeUpper)
		{
			finalStr += *itr - 32;
			makeUpper = false;
		}
		else
		{
			finalStr += *itr;
		}
	}
	return finalStr;
}
