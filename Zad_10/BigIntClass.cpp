#include "BigIntClass.h"

BigInt::BigInt()
    : _number(0)
{
    _number.push_back(0);
}

BigInt::BigInt(long long number)
{
    do{
        _number.push_back(number % 10);
        number /= 10;
    }while (number);
}

BigInt::BigInt(const BigInt& second)
{
    std::vector<short int> tmp = second._number;
    std::copy(tmp.begin(), tmp.end(), std::back_inserter(_number));

}

BigInt::~BigInt()
{
}

std::vector<short int> BigInt::getNum() const
{
    return _number;
}

int BigInt::getSizeNum() const
{
    return _number.size();
}


std::string BigInt::toString() const
{
    std::string numInStr;
    for (auto it = _number.begin(); it != _number.end(); ++it)
    {
        numInStr += *it + 48;
    }
    std::reverse(numInStr.begin(), numInStr.end());
    return numInStr;
}
BigInt& BigInt::operator=(const BigInt& a)
{
    _number.clear();
    std::copy(a._number.begin(), a._number.end(), std::back_inserter(_number));

    return *this;
}

//int shorterBigInt(const BigInt& a, const BigInt& b)
//{
//    if (a.getSizeNum() <= b.getSizeNum())
//    {
//        return a.getSizeNum();
//    }
//    else
//    {
//        return b.getSizeNum();
//    }
//}
int longerBigInt(const BigInt& a, const BigInt& b)
{
    if (a.getSizeNum() <= b.getSizeNum())
    {
        return b.getSizeNum();
    }
    else
    {
        return a.getSizeNum();
    }
}
BigInt operator+(const BigInt& a, const BigInt& b)
{
    BigInt c;
    int tmp = 0;
    int result = 0;
    int counter = 0;
    short int aVar = 0;
    short int bVar = 0;

    std::vector<short int> aMmember = a.getNum();
    std::vector<short int> bMmember = b.getNum();
    
    c._number.clear();

    for (size_t i = 0; i < longerBigInt(a, b); ++i)
    {
        if (i >= aMmember.size())
        {
            aVar = 0;
        }
        else
        {
            aVar = aMmember[i];
        }
        if (i >= bMmember.size())
        {
            bVar = 0;
        }
        else
        {
            bVar = bMmember[i];
        }

        result = aVar + bVar + tmp;
        tmp = 0;
        if (result >= 10)
        {
            tmp = 1;
            c._number.push_back(result % 10);
        }
        else
        {
            c._number.push_back(result);
        }
       /* ++counter;*/
    }
    if (tmp != 0)
    {
        c._number.push_back(tmp);
    }

    //if (aMmember.size() == counter)
    //{
    //    for (size_t i = counter; i < longerBigInt(a, b); ++i)
    //    {
    //        c._number.push_back(bMmember[counter]+tmp);
    //        tmp = 0;
    //    }
    //}
    //else if (bMmember.size() == counter)
    //{
    //    for (size_t i = counter; i < longerBigInt(a, b); ++i)
    //    {
    //        c._number.push_back(aMmember[counter] + tmp);
    //        tmp = 0;
    //    }
    //}
 
    return c;
}

int iterations(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

BigInt operator*(const BigInt& a, const BigInt& b)
{
    BigInt c;
    c._number.clear();
    std::vector<BigInt> results;
    int aSize = a.getSizeNum();
    int bSize = b.getSizeNum();
    std::vector<short int> aMmember = a.getNum();
    std::vector<short int> bMmember = b.getNum();

    for (size_t i = 0; i <aSize; ++i)
    {
        int carry = 0;

        BigInt f;
        f._number.clear();

        for (size_t j = 0; j < bSize; ++j)
        {
            int result = aMmember[i] * bMmember[j] + carry;
            f._number.push_back(result % 10);
            carry = result / 10;
        }
        if (carry != 0)
        {
            f._number.push_back(carry);
        }

        auto it = f._number.begin();
        f._number.insert(it, i, 0);
        
        results.push_back(f);
    }

    for (size_t i = 0; i < results.size(); ++i)
    {
        c = c + results[i];
    }

    return c;
}
BigInt operator/(const BigInt& a, const BigInt& b)
{
    BigInt temp;
    return temp;
}
BigInt operator%(const BigInt& a, const BigInt& b)
{
    BigInt temp;
    return temp;
}
bool operator<(const BigInt& a, const BigInt& b)
{
    std::vector<short int> vectorA = a.getNum();
    std::vector<short int> vectorB = b.getNum();
    int sizeA = a.getSizeNum();
    int sizeB = b.getSizeNum();

    if (sizeA != sizeB)
    {
        return sizeA < sizeB;
    }
    for (size_t i = sizeA; i > 0 ; --i)
    {
        return vectorA[i] < vectorB[i];
    }
    return false;
}
bool operator>(const BigInt& a, const BigInt& b)
{
    std::vector<short int> vectorA = a.getNum();
    std::vector<short int> vectorB = b.getNum();
    int sizeA = a.getSizeNum();
    int sizeB = b.getSizeNum();

    if (sizeA != sizeB)
    {
        return sizeA > sizeB;
    }
    for (size_t i = sizeA; i > 0; --i)
    {
        return vectorA[i] > vectorB[i];
    }
    return false;
}
bool operator<=(const BigInt& a, const BigInt& b)
{
    return (a==b)||(a<b);
}
bool operator>=(const BigInt& a, const BigInt& b)
{
    return (a == b) || (a > b);
}

bool operator==(const BigInt& a, const BigInt& b)
{
    std::vector<short int> vectorA = a.getNum();
    std::vector<short int> vectorB = b.getNum();
    int sizeA = a.getSizeNum();
    int sizeB = b.getSizeNum();
    bool result = false;
    if (sizeA == sizeB)
    {
        for (size_t i = 0; i < sizeA; --i)
        {
           if (vectorA[i] == vectorB[i])
           {
               result = true;
           }
           else
           {
               result = false;
           }
        }
    }
    else
    {
        result = false;
    }
    
    return result;
}