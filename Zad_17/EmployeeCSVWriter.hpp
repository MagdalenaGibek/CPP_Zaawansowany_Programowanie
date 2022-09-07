#pragma once
#include "EmployeeFileWriter.hpp"

#include <vector>

class EmployeeCSVWriter : public EmployeeFileWriter
{
public:
	void writeEmployees(std::vector<Employee> employees, std::string filePath) override;


private:
};