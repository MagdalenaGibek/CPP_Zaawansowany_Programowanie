#include "EmployeeManager.hpp"

void EmployeeManager::readDataFromFile(std::string filePath)
{
	employees = _fileReader->readEmployees(filePath);
}
