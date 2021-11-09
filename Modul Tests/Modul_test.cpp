#include "../CPP Labs - 2021/string.h"
#include <gmock/gmock.h>
#define DEBUG_LINES

TEST(Constructor, DefaultConstructor) {
	string<char> test;
	EXPECT_EQ(test.GetData(), nullptr);
	EXPECT_EQ(test.GetSize(), 0);
}


TEST(Constructor, CopyConstructor) {
	string<char> test("test", 4);
	string<char> test1(test);
	EXPECT_EQ(test.GetSize(), test1.GetSize());
}

TEST(Operator, AssignmentOperatorChar) {
	string<char>  test1("test123", 7);
	string<char> test2;
	test2 = test1;
	EXPECT_EQ(test1.GetSize(), test2.GetSize());
	auto data = test1.GetData();
	test1 = test1;
	EXPECT_EQ(test1.GetData(), data);
}

TEST(Operator, AssignmentOperatorInt) {
	int vector_int[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	string<int> test_int1(vector_int, 10);
	string<int> test_int2;
	test_int2 = test_int1;
	EXPECT_EQ(test_int1.GetSize(), test_int2.GetSize());
	for (size_t i = 0; i < 10; ++i) {
		EXPECT_EQ(test_int1[i], test_int2[i]);
	}
	auto data = test_int1.GetData();
	test_int1 = test_int1;
	EXPECT_EQ(test_int1.GetData(), data);
}


TEST(Operator, AssignmentOperatorDouble) {
	double vector_double[10] = { 11.28, 13.22, 21.17, 3.14, 4.41, 5.73, 6.90, 7.1, 8.1238812, 9.0 };
	string<double> test_double(vector_double, 10);
	string<double> test_double2;
	test_double2 = test_double;
	EXPECT_EQ(test_double.GetSize(), test_double2.GetSize());
	for (size_t i = 0; i < 10; ++i) {
		EXPECT_EQ(test_double[i], test_double2[i]);
	}
	auto data = test_double.GetData();
	test_double = test_double;
	EXPECT_EQ(test_double.GetData(), data);
}


TEST(Operator, Operator_index_const) {
	const string<char> test_char("test", 4);
	EXPECT_EQ(test_char[0], 't');
	EXPECT_EQ(test_char[2], 's');
	EXPECT_THROW(test_char[15], std::out_of_range);
	int vector_int[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	const string<int> test_int(vector_int, 6);
	EXPECT_EQ(test_int[2], 2);
	EXPECT_EQ(test_int[5], 5);
	EXPECT_THROW(test_int[15], std::out_of_range);
	double vector_double[10] = { 11.28, 13.22, 21.17, 3.14, 4.41, 5.73, 6.90, 7.1, 8.1238812, 9.0 };
	const string<double> test_double(vector_double , 10);
	EXPECT_EQ(test_double[8], 8.1238812);
	EXPECT_EQ(test_double[3], 3.14);
	EXPECT_THROW(test_double[15], std::out_of_range);
}

TEST(Operator, Operator_index) {
	string<char> test_char("test", 4);
	test_char[0] = 'n';
	EXPECT_EQ(test_char[0], 'n');
	EXPECT_THROW(test_char[15], std::out_of_range);
	
	int vector_int[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	string<int> test_int(vector_int, 8);
	test_int[0] = 221;
	EXPECT_EQ(test_int[0], 221);
	EXPECT_THROW(test_int[15], std::out_of_range);
	
	double vector_double[10] = { 11.28, 13.22, 21.17, 3.14, 4.41, 5.73, 6.90, 7.1, 8.1238812, 9.0 };
	string<double> test_double(vector_double, 10);
	test_double[2] = 13.11;
	EXPECT_EQ(test_double [2] , 13.11);
	EXPECT_THROW(test_double [15] , std::out_of_range);

}

TEST(Operator, Operator_pluseq_char) {
	string<char> test_char("test", 4);
	test_char += 's';
	EXPECT_EQ(test_char[4], 's');

	int vector_int[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	string<int> test_int(vector_int, 10);
	test_int += 224;
	EXPECT_EQ(test_int[10], 224);

	double vector_double[10] = { 11.28, 13.22, 21.17, 3.14, 4.41, 5.73, 6.90, 7.1, 8.1238812, 9.0 };
	string<double> test_double (vector_double, 10);
	test_double += 3.1415;
	EXPECT_EQ(test_double[10], 3.1415);
}

TEST(Operator, Operator_pluseq_sting_char) {
	string<char> test1("test", 4);
	string<char> test2("ing", 3);
	test1 += test2;
	EXPECT_EQ(test1[4], 'i');
	EXPECT_EQ(test1[5], 'n');
	EXPECT_EQ(test1[6], 'g');
}

TEST(Operator, Operator_pluseq_sting_int) {
	int vector_int[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	string<int> test1(vector_int, 4);
	string<int> test2(vector_int, 3);
	test1 += test2;
	EXPECT_EQ(test1[4], 0);
	EXPECT_EQ(test1[5], 1);
	EXPECT_EQ(test1[6], 2);
}

TEST(Operator, Operator_pluseq_sting_double) {
	double vector_double[10] = { 11.28, 13.22, 21.17, 3.14, 4.41, 5.73, 6.90, 7.1, 8.1238812, 9.0 };
	string<double> test1(vector_double, 4);
	string<double> test2(vector_double, 6);
	test1 += test2;
	EXPECT_EQ(test1[6], 21.17);
	EXPECT_EQ(test1[7], 3.14);
	EXPECT_EQ(test1[8], 4.41);
}

TEST(Operator, Operator_equals_char) {
	string<char> test1("test", 4);
	string<char> test2(test1);
	string<char> test3("test", 4);
	EXPECT_TRUE(test1 == test2);
	EXPECT_TRUE(test1 == test3);
	EXPECT_TRUE(test2 == test3);
}

TEST(Operator, Operator_equals_int) {
	int vector_int[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	string<int> test1(vector_int, 4);
	string<int> test2(test1);
	string<int> test3(vector_int, 4);
	EXPECT_TRUE(test1 == test2);
	EXPECT_TRUE(test1 == test3);
	EXPECT_TRUE(test2 == test3);
}

TEST(Operator, Operator_equals_double) {
	double vector_double[10] = { 11.28, 13.22, 21.17, 3.14, 4.41, 5.73, 6.90, 7.1, 8.1238812, 9.0 };
	string<double> test1(vector_double, 8);
	string<double> test2(test1);
	string<double> test3(vector_double , 8);
	EXPECT_TRUE(test1 == test2);
	EXPECT_TRUE(test1 == test3);
	EXPECT_TRUE(test2 == test3);
}

TEST(Operator, Operator_mul_char) {
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
	EXPECT_THROW(test2[6], std::out_of_range);
	EXPECT_EQ(test1 * 3, 3 * test1);
}

TEST(Operator, Operator_mul_int) {
	int vector_int[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	string<int> test1(vector_int, 3);
	string<int> test2 = test1 * 3;
	string<int> test3 = 3 * test1;
	EXPECT_EQ(test2[3], 0);
	EXPECT_EQ(test2[4], 1);
	EXPECT_EQ(test2[5], 2);
	EXPECT_EQ(test2[6], 0);
	EXPECT_EQ(test3[3], 0);
	EXPECT_EQ(test3[4], 1);
	EXPECT_EQ(test3[5], 2);
	EXPECT_EQ(test3[6], 0);
	EXPECT_THROW(test2[10], std::out_of_range);
	EXPECT_EQ(test1 * 3, 3 * test1);
}

TEST(Operator, Operator_mul_double) {
	double vector_double[10] = { 11.28, 13.22, 21.17, 3.14, 4.41, 5.73, 6.90, 7.1, 8.1238812, 9.0 };
	string<double> test1(vector_double, 3);
	string<double> test2 = test1 * 3;
	string<double> test3 = 3 * test1;
	EXPECT_EQ(test2[3], 11.28);
	EXPECT_EQ(test2[4], 13.22);
	EXPECT_EQ(test2[5], 21.17);
	EXPECT_EQ(test2[6], 11.28);
	EXPECT_EQ(test3[3], 11.28);
	EXPECT_EQ(test3[4], 13.22);
	EXPECT_EQ(test3[5], 21.17);
	EXPECT_EQ(test3[6], 11.28);
	EXPECT_THROW(test2[10], std::out_of_range);
	EXPECT_EQ(test1 * 3, 3 * test1);
}

TEST(Function, Substr_char) {
	string<char> test1("testing", 7);
	string<char> test2_0 = test1.SubStr(0, 2);
	string<char> test2_1("te", 2);
	EXPECT_EQ(test2_1[0], 't');
	EXPECT_EQ(test2_1[1], 'e');
	EXPECT_THROW(test2_1[2], std::out_of_range);
	EXPECT_TRUE(test2_0 == test2_1);
}

TEST(Function, Substr_int) {
	int vector_int[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	string<int> test1(vector_int, 7);
	string<int> test2_0 = test1.SubStr(0, 2);
	int vector_test[3] = { 0 , 1};
	string<int> test2_1(vector_test, 2);
	EXPECT_EQ(test2_1[0], 0);
	EXPECT_EQ(test2_1[1], 1);
	EXPECT_THROW(test2_1[2], std::out_of_range);
	EXPECT_TRUE(test2_0 == test2_1);
}

TEST(Function, Substr_double) {
	double vector_double[10] = { 11.28, 13.22, 21.17, 3.14, 4.41, 5.73, 6.90, 7.1, 8.1238812, 9.0 };
	string<double> test1(vector_double, 7);
	string<double> test2_0 = test1.SubStr(0, 2);
	double vector_test[3] = { 11.28, 13.22 };
	string<double> test2_1(vector_test, 2);
	EXPECT_EQ(test2_1[0], 11.28);
	EXPECT_EQ(test2_1[1], 13.22);
	EXPECT_THROW(test2_1[2], std::out_of_range);
	EXPECT_TRUE(test2_0 == test2_1);
}
