// Napisz klasę StringConverter, która bedzie miała dwie metody (statyczne):
//std::string toCamelCase(std::string)
//std::string toSnakeCase(std::string)
//camelCase : snake_case
//helloSDA : hello_S_D_A
//getColour : get_colour
//isThisFirstEntry : is_this_first_entry

#pragma once
#include<string>

class StringConverter
{
public:
	StringConverter();
	virtual ~StringConverter();
	static std::string toCamelCase(std::string str);
	static std::string toSnakeCase(std::string str);
}; 