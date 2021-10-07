#include "../CPP Labs - 2021/string.h"
#include <gmock/gmock.h>
#define DEBUG_LINES

TEST(Constructor, DefaultConstructor) {
	string test;
	EXPECT_EQ(test.GetData(), nullptr);
	EXPECT_EQ(test.GetSize(), 0);
	EXPECT_EQ(test.GetCapacity(), 0);
}

TEST(Constructor, ParameterConstructor) {
	string test("test");
	EXPECT_EQ(test.GetSize(), (size_t)strlen(test.GetData()));
	EXPECT_EQ(strcmp(test.GetData(), "test"), 0);
}

TEST(Constructor, CopyConstructor) {
	string test("test");
	string test1(test);
	EXPECT_EQ(test.GetSize(), test1.GetSize());
	EXPECT_EQ(strcmp(test.GetData(), test1.GetData()), 0);
}

TEST(Operator, Operator_index) {
	string test("test");

}