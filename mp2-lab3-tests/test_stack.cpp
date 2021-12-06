#include "gtest.h"
#include "..\stack\Stack.h"


TEST(TStack, can_create_stack_with_positive_size)
{
	ASSERT_NO_THROW(TStack<int> ts);
}
TEST(TStack, cant_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(TStack<int>ts(-4));
}

TEST(TStack, cant_create_stack_with_zero_size) {
	ASSERT_ANY_THROW(TStack<int>ts(0));
}

TEST(TStack, can_create_copied_stack) {
	TStack<int> ts(10);

	ASSERT_NO_THROW(TStack<int> copy = ts);
}
TEST(TStack, copied_stack_is_equal_to_source_one) {
	TStack<int> ts(5);
	for (int i = 0; i < 5; i++)
	{
		ts.Push(i);
	}
	//
	TStack<int> copy(ts);
	EXPECT_EQ(copy, ts);
}

TEST(TStack, copied_stack_has_its_own_memory) {
	TStack<int> ts(5);
	for (int i = 0; i < 5; i++)
	{
		ts.Push(i);
	}
	TStack<int> copy(ts);
	copy.Clear();
	for (int i = 0; i < 5; i++)
	{
		copy.Push(i + 1);
	}

	for (int i = 0; i < 5; i++) {
		EXPECT_NE(ts.Pop(), copy.Pop());
	}
}

TEST(TStack, can_assign_stacks_of_equal_size) {
	TStack<int> ts1(5);
	for (int i = 0; i < 5; i++)
	{
		ts1.Push(i);
	}

	TStack<int> ts2(5);
	for (int i = 0; i < 5; i++)
	{
		ts2.Push(2 * i);
	}

	ts2 = ts1;

	EXPECT_EQ(ts2, ts1);
}

TEST(TStack, equal_stacks_comparison_returns_true) {
	TStack<int> ts1(7);
	for (int i = 0; i < 7; i++)
	{
		ts1.Push(i);
	}

	TStack<int> ts2(7);
	for (int i = 0; i < 7; i++)
	{
		ts2.Push(i);
	}

	EXPECT_EQ(ts1, ts2);
}
TEST(TStack, can_assign_stacks_of_different_size) {
	TStack<int> ts1(8);
	for (int i = 0; i < 8; i++)
		ts1.Push(i);

	TStack<int> ts2(15);
	for (int i = 0; i < 15; i++)
		ts2.Push(2 * i);
	ts2 = ts1;

	EXPECT_EQ(ts2, ts1);
}

TEST(TStack, can_assign_stack_to_itself) {
	TStack<int> ts(5);
	for (int i = 0; i < 5; i++)
	{
		ts.Push(i);
	}

	ts = ts;

	EXPECT_EQ(ts, ts);
}

TEST(TStack, unequal_stacks_comparison_returns_false)
{
	TStack<int> ts1(5);
	for (int i = 0; i < 5; i++)
	{
		ts1.Push(i);
	}

	TStack<int> ts2(5);
	for (int i = 0; i < 5; i++)
	{
		ts2.Push(2 * i);
	}

	EXPECT_NE(ts1, ts2);
}

TEST(TStack, stacks_with_different_sizes_are_not_equal)
{
	TStack<int> ts1(4);
	TStack<int> ts2(10);

	EXPECT_NE(ts1, ts2);
}

TEST(TStack, empty_stack_isempty_returns_true)
{
	TStack<int> ts(5);

	ASSERT_TRUE(ts.IsEmpty());
}

TEST(TStack, not_empty_stack_isempty_returns_false)
{
	TStack<int> ts(5);
	ts.Push(5);

	ASSERT_FALSE(ts.IsEmpty());
}

TEST(TStack, full_stack_isfull_returns_true)
{
	TStack<int> ts(5);
	for (int i = 0; i < 5; i++)
		ts.Push(i);

	ASSERT_TRUE(ts.IsFull());
}

TEST(TStack, not_full_stack_isfull_returns_false)
{
	TStack<int> ts(5);

	ASSERT_FALSE(ts.IsFull());
}

TEST(TStack, can_push_and_pop)
{
	TStack<int> ts(4);
	int elem = 4;
	int poped;

	ASSERT_NO_THROW(ts.Push(elem));
	ASSERT_NO_THROW(poped = ts.Pop());
	EXPECT_EQ(poped, elem);
}

TEST(TStack, cant_push_when_stack_is_full) 
{
	TStack<int> ts(20);
	for (int i = 0; i < 20; i++)
	{
		ts.Push(i);
	}

	ASSERT_ANY_THROW(ts.Push(20));
}

TEST(TStack, cant_pop_when_stack_is_empty)
{
	TStack<int> ts(5);

	ASSERT_ANY_THROW(ts.Pop());
}

TEST(TStack, can_give_top) 
{
	TStack<int> ts(10);
	ts.Push(10);

	EXPECT_EQ(ts.Top(), 10);
}

TEST(TStack, cant_give_top_when_stack_is_empty)
{
	TStack<int> ts(15);

	ASSERT_ANY_THROW(ts.Top());
}

TEST(TStack, can_clear_stack)
{
	TStack<int> ts(10);
	for (int i = 0; i < 10; i++)
		ts.Push(i);

	ASSERT_NO_THROW(ts.Clear());
}