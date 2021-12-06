#include "gtest.h"
#include "..\stack\Calc.h"

TEST(TCalc, can_create_calculator) {
	ASSERT_NO_THROW(TCalc tc);
}

TEST(TCalc, can_check_brackets) {
	string expr = "(1 + 2)";
	TCalc tc(expr);

	ASSERT_NO_THROW(tc.CorrectBrackets());
}

TEST(TCalc, can_detect_correct_brackets) {
	string expr = "(1 + 2)";
	TCalc tc(expr);

	ASSERT_TRUE(tc.CorrectBrackets());
}

TEST(TCalc, can_detect_incorrect_brackets) {
	string expr = "1 + 212)(";
	TCalc tc(expr);

	ASSERT_FALSE(tc.CorrectBrackets());
}

TEST(TCalc, can_convert_to_postfix) {
	string expr = "4^(3 - 2) + 1";
	TCalc tc(expr);

	ASSERT_NO_THROW(tc.ToPostfix());
	EXPECT_EQ(tc.GetPostfix(), "4 3 2 - ^ 1 +");
}

TEST(TCalc, can_add) {
	string expr = "1 + 11";
	TCalc tc(expr);

	tc.ToPostfix();

	EXPECT_EQ(tc.Calc(), 12);
}

TEST(TCalc, can_substract) {
	string expr = "2 - 1";
	TCalc tc(expr);

	tc.ToPostfix();

	EXPECT_EQ(tc.Calc(), 1);
}

TEST(TCalc, can_multiply) {
	string expr = "11 * 2";
	TCalc tc(expr);

	tc.ToPostfix();

	EXPECT_EQ(tc.Calc(), 22);
}

TEST(TCalc, can_divide) {
	string expr = "12 / 4";
	TCalc tc(expr);

	tc.ToPostfix();

	EXPECT_EQ(tc.Calc(), 3);
}

TEST(TCalc, can_raise_to_the_power)
{
	string expr = "3 ^ 4";
	TCalc tc(expr);

	tc.ToPostfix();

	EXPECT_EQ(tc.Calc(), 81);
}

TEST(TCalc, can_calculate_complex_expression) {
	string expr = "(7*12)-2^(14-11)*2-21/3";
	TCalc tc(expr);

	tc.ToPostfix();

	EXPECT_EQ(tc.Calc(), 61);
}