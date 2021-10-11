#include "../CPP Labs - 2021/string.h"
#include <gmock/gmock.h>
#define DEBUG_LINES

TEST(Constructor, DefaultConstructor) {
	string<char> test;
	EXPECT_EQ(test.GetData(), nullptr);
	EXPECT_EQ(test.GetSize(), 0);
	EXPECT_EQ(test.GetCapacity(), 0);
}


TEST(Constructor, CopyConstructor) {
	string<char> test("test", 4);
	string<char> test1(test);
	EXPECT_EQ(test.GetSize(), test1.GetSize());
	EXPECT_EQ(strcmp(test.GetData(), test1.GetData()), 0);
}

TEST(Operator, Operator_index_const) {
	const string<char> test("test", 4);
	EXPECT_EQ(test[0], 't');
	EXPECT_EQ(test[2], 's');
	EXPECT_THROW(test[15], const char*);
}

TEST(Operator, Operator_index) {
	string<char> test("test", 4);
	test[0] = 'n';
	EXPECT_EQ(test[0], 'n');
	EXPECT_THROW(test[15], const char*);
}

TEST(Operator, Operator_pluseq_char) {
	string<char> test("test", 4);
	test += 's';
	EXPECT_EQ(test[4], 's');
}

TEST(Operator, Operator_pleseq_sting) {
	string<char> test1("test", 4);
	string<char> test2("ing", 3);
	test1 += test2;
	EXPECT_EQ(test1[4], 'i');
	EXPECT_EQ(test1[5], 'n');
	EXPECT_EQ(test1[6], 'g');
}

TEST(Operator, Operator_equals) {
	string<char> test1("test", 4);
	string<char> test2(test1);
	string<char> test3("test", 4);
	EXPECT_TRUE(test1 == test2);
	EXPECT_TRUE(test1 == test3);
	EXPECT_TRUE(test2 == test3);
}

TEST(Operator, Operator_mul) {
	string<char> test1("ab", 2);
	string<char> test2 = test1 * 3;
	string<char> test3 = 3 * test1;
	EXPECT_EQ(test2[2], 'a');
	EXPECT_EQ(test2[3], 'b');
	EXPECT_EQ(test2[4], 'a');
	EXPECT_EQ(test2[5], 'b');
	EXPECT_EQ(test3[2], 'a');
	EXPECT_EQ(test3[3], 'b');
	EXPECT_EQ(test3[4], 'a');
	EXPECT_EQ(test3[5], 'b');
	EXPECT_THROW(test2[6], const char*);
	EXPECT_EQ(test1 * 3, 3 * test1);
}

TEST(Function, Substr) {
	string<char> test1("testing", 7);
	string<char> test2_0 = test1.SubStr(0, 2);
	string<char> test2_1("te", 2);
	EXPECT_EQ(test2_1[0], 't');
	EXPECT_EQ(test2_1[1], 'e');
	EXPECT_THROW(test2_1[2], const char*);
	EXPECT_TRUE(test2_0 == test2_1);
}
