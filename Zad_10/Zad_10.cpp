
#include "BigIntClass.h"
#include <iostream>

int main()
{
    BigInt num(2435836);
    BigInt num2(num);
    BigInt num3(55);
    BigInt num4(55);

    BigInt num6(4383);
    BigInt num7(36);

    std::cout << num.toString()<<std::endl;
    std::cout << num2.toString() << std::endl;
    num2 = 456;
    std::cout << num2.toString() << std::endl;
    BigInt num5 = num3 + num4;
    std::cout << num5.toString() << std::endl;
    BigInt num8 = num6 * num7;
    std::cout << num8.toString();


 
}

