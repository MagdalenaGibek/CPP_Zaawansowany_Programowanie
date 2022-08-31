
#include <iostream>
#include "StringConverterClass.hpp"

int main()
{
	StringConverter text;
	std::cout<<text.toCamelCase("camelCase")<<std::endl;
	std::cout << text.toSnakeCase("snake_case") << std::endl;
	std::cout << text.toSnakeCase("get_colour") << std::endl;
	std::cout << text.toSnakeCase("is_this_first_entry") << std::endl;
}

