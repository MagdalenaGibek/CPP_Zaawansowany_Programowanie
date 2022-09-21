#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

class BigInt
{
public:
	BigInt();
	BigInt(long long number);
	BigInt(const BigInt& second);
	virtual~BigInt();
	std::vector<short int> getNum() const;
	int getSizeNum() const;
	std::string toString() const;
	BigInt& operator=(const BigInt& a);
	friend BigInt operator+(const BigInt& a, const BigInt& b);
	friend BigInt operator*(const BigInt& a, const BigInt& b);
protected:
	std::vector<short int>_number;
};

BigInt operator+(const BigInt& a, const BigInt& b);
BigInt operator*(const BigInt& a, const BigInt& b);
BigInt operator/(const BigInt& a, const BigInt& b);
BigInt operator%(const BigInt& a, const BigInt& b);
bool operator<(const BigInt& a, const BigInt& b);
bool operator>(const BigInt& a, const BigInt& b);
bool operator<=(const BigInt& a, const BigInt& b);
bool operator>=(const BigInt& a, const BigInt& b);
bool operator==(const BigInt& a, const BigInt& b);