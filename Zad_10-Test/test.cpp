#include "pch.h"
#include "../Zad_10/BigIntClass.h"

TEST(ToStringTest, toString_Conversion) {
	BigInt num(1234569874564523558);
	std::string convertedNum = num.toString();
	EXPECT_EQ(convertedNum,"1234569874564523558");
}

TEST(AssignmentOperatorTest, first_Obj_Same_As_Second_Obj) {
	BigInt num(1234569874564523545);
	BigInt num2(num);
	EXPECT_EQ(num2, 1234569874564523545);
}

TEST(PlusOperatorTest, Result_Is_Equal_6413196) {
	BigInt num1(1564684);
	BigInt num2(4848512);
	EXPECT_EQ(num1+ num2, 6413196);
}

TEST(EqualsOperatorTest, Equals_Test) {
	BigInt num(12345698745645235);
	BigInt num2(num);
	EXPECT_TRUE(num == num2);
}
TEST(EqualsOperatorTest, Not_Equals_Test) {
	BigInt num(12345698745645235);
	BigInt num2(12345698745645232);
	EXPECT_FALSE(num == num2);
}

TEST(MultiplyOperatorTest, Result_Is_Equal_2211858476) {
	BigInt num1(46588);
	BigInt num2(47477);
	EXPECT_EQ(num1 * num2, 2211858476);
}

TEST(DivisionOperatorTest, ResultIsEqual561168) {
	BigInt num1(12345698);
	BigInt num2(22);
	EXPECT_EQ(num1 / num2, 561168);
}

TEST(ModuloOperatorTest, ResultIsEqual2) {
	BigInt num1(12345698);
	BigInt num2(22);
	EXPECT_EQ(num1 % num2, 2);
}

TEST(ComparisionOperatorTest, First_Bigger_Than_Second) {
	BigInt num1(12345698462);
	BigInt num2(12345698);
	EXPECT_TRUE(num1 > num2);
}

TEST(ComparisionOperatorTest, FirstI_Lower_Than_Second) {
	BigInt num1(3234569);
	BigInt num2(12345698);
	EXPECT_TRUE(num1 < num2);
}

TEST(ComparisionOperatorTest, First_Equal_Or_Bigger_Than_Second) {
	BigInt num1(22654645654645);
	BigInt num2(226546456546);
	EXPECT_TRUE(num1 >= num2);
}

TEST(ComparisionOperatorTest, First_Equal_Second) {
	BigInt num1(22654645654645);
	BigInt num2(22654645654645);
	EXPECT_TRUE(num1 == num2);
}

TEST(ComparisionOperatorTest, First_Equal_Or_Lower_Than_Second) {
	BigInt num1(12345698);
	BigInt num2(4563456984867);
	EXPECT_TRUE(num1 <= num2);

}

TEST(ComparisionOperatorTest, First_Equal_Second_2nd_Case) {
	BigInt num1(4563456984867);
	BigInt num2(4563456984867);
	EXPECT_TRUE(num1 == num2);

}

TEST(ComparisionOperatorTest, First_Equal_Second_3rd_Case) {
	BigInt num1(12345698);
	BigInt num2(12345698);
	EXPECT_TRUE(num1 == num2);
}



