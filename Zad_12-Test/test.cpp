#include "pch.h"
#include "..\Zad_12\CircularBufferClass.hpp"
TEST(TestIntCapacity, CapacacityEqual7) {

	CircularBuffer<int> cirbuf(7);
	EXPECT_EQ(7, cirbuf.capacity());
}

TEST(TestStringCapacity, CapacacityEqual5) {

	CircularBuffer<std::string> cirbuf(5);
	EXPECT_EQ(5, cirbuf.capacity());
}
TEST(TestPushBack, Element0Equal10) {

	CircularBuffer<int> cirbuf(7);
	cirbuf.push_back(10);
	EXPECT_EQ(cirbuf[0], 10);
}

TEST(TestPushBack, AddedElementsFrom0to3) {

	CircularBuffer<int> cirbuf(4);
	for (size_t i = 0; i < cirbuf.capacity(); ++i)
	{
		cirbuf[i] = i;
	}
	EXPECT_EQ(cirbuf[0], 0);
	EXPECT_EQ(cirbuf[1], 1);
	EXPECT_EQ(cirbuf[2], 2);
	EXPECT_EQ(cirbuf[3], 3);
}

TEST(TestPushBack, AddedTooManyElements) {

	CircularBuffer<int> cirbuf(3);
	for (size_t i = 0; i < cirbuf.capacity(); ++i)
	{
		cirbuf[i] = i;
	}
	EXPECT_EQ(cirbuf[0], 0);
	EXPECT_EQ(cirbuf[1], 1);
	EXPECT_EQ(cirbuf[2], 2);
	EXPECT_EQ(cirbuf[3], 3);
}

TEST(TestSize, TestSizeEqual4) {

	CircularBuffer<int> cirbuf(7);
	for (size_t i = 0; i < 4; ++i)
	{
		cirbuf.push_back(i);
	}
	EXPECT_EQ(cirbuf.size(), 4);
	
}
TEST(TestSize, TestSizeEqual3) {

	CircularBuffer<int> cirbuf(3);
	for (size_t i = 0; i < 3; ++i)
	{
		cirbuf.push_back(i);
	}
	EXPECT_EQ(cirbuf.size(), 3);
}

TEST(TestSize, value0isOverwrittenBy3) { // czy tutaj dobrze jest nazwany test

	CircularBuffer<int> cirbuf(3);
	for (size_t i = 0; i < 4; ++i)
	{
		cirbuf.push_back(i);
	}
	EXPECT_EQ(cirbuf[0], 3);
}

TEST(TestPopBack, removedElementEquals2) {// czy tutaj dobrze jest nazwany test

	CircularBuffer<int> cirbuf(7);
	for (size_t i = 0; i < 3; ++i)
	{
		cirbuf.push_back(i);
	}
	EXPECT_EQ(cirbuf.pop_back(), 2);
	EXPECT_EQ(cirbuf.size(), 2);
}

TEST(TestPopBack, removedElementEquals0) {

	CircularBuffer<int> cirbuf(7);
	for (size_t i = 0; i < 3; ++i)
	{
		cirbuf.push_back(i);
	}
	cirbuf.pop_front();
	cirbuf.pop_front();
	cirbuf.push_back(0);
	EXPECT_EQ(cirbuf.pop_back(), 0);
	EXPECT_EQ(cirbuf.size(), 1);
}

TEST(TestPopBack, BufferIsEmpty) {

	CircularBuffer<int> cirbuf(7);

	EXPECT_EQ(cirbuf.pop_back(), -1);
	EXPECT_EQ(cirbuf.size(), 0);
}
TEST(TestPopFront, removedElementEquals0) {

	CircularBuffer<int> cirbuf(7);
	for (size_t i = 0; i < 3; ++i)
	{
		cirbuf.push_back(i);
	}
	EXPECT_EQ(cirbuf.pop_front(), 0);
	EXPECT_EQ(cirbuf.size(), 2);
}

TEST(TestPopFront, removedElementEquals1) {

	CircularBuffer<int> cirbuf(7);
	for (size_t i = 0; i < 3; ++i)
	{
		cirbuf.push_back(i);
	}
	cirbuf.pop_front();
	cirbuf.pop_front();
	cirbuf.push_back(1);
	EXPECT_EQ(cirbuf.pop_front(), 2);
	EXPECT_EQ(cirbuf.size(), 1);
}

TEST(TestPopFront, BufferIsEmpty) {

	CircularBuffer<int> cirbuf(7);

	EXPECT_EQ(cirbuf.pop_front(), -1);
	EXPECT_EQ(cirbuf.size(), 0);
}

TEST(TestResize, increasedBufferEquals14) {

	CircularBuffer<int> cirbuf(7);
	cirbuf.resize(14);
	EXPECT_EQ(cirbuf.capacity(), 14);
}

TEST(TestInsert, position2equals5) {

	CircularBuffer<int> cirbuf(7);
	for (size_t i = 0; i < 4; ++i)
	{
		cirbuf.push_back(i);
	}
	cirbuf.insert(2, 5);
	EXPECT_EQ(cirbuf[2], 5);
	EXPECT_EQ(cirbuf.size(), 5);
}

TEST(TestInsert, position4equals7) {

	CircularBuffer<int> cirbuf(6);
	for (size_t i = 0; i < 6; ++i)
	{
		cirbuf.push_back(i);
	}
	cirbuf.pop_back();
	cirbuf.pop_back();
	cirbuf.pop_back();
	cirbuf.push_back(1);
	cirbuf.insert(4, 7);
	EXPECT_EQ(cirbuf[4], 7);
	EXPECT_EQ(cirbuf[1], 1);
	EXPECT_EQ(cirbuf.size(), 5);
}

