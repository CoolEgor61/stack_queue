#include "mStack.h"
#include "gtest.h"

TEST(mStack, can_create_mStack)
{
    ASSERT_NO_THROW(mStack<int> s);
}

TEST(mStack, can_check_for_empty)
{
    mStack<int> s;
    EXPECT_EQ(1, s.isEmpty());
}

TEST(mStack, can_check_for_full1)
{
    mStack<int> s;
    EXPECT_NE(1, s.isFull());
}

TEST(mStack, can_check_for_full2)
{
    mStack<int> s;
    s.push(1);
    EXPECT_EQ(1, s.isFull());
}

TEST(mStack, can_return_correct_size)
{
    mStack<int> s;
    s.push(1); s.push(1); s.push(1); s.push(1); s.push(1);
    EXPECT_EQ(5, s.size_());
}

TEST(mStack, can_return_correct_capacity)
{
    mStack<int> s;
    s.push(1); s.push(1); s.push(1); s.push(1); s.push(1);
    EXPECT_EQ(2*2+2, s.capacity_());
}

TEST(mStack, can_push_element)
{
    mStack<int> s;
    s.push(1);
    EXPECT_EQ(1, s.top());
}

TEST(mStack, can_pop_element)
{
    mStack<int> s;
    s.push(6);
    s.push(21);
    s.pop();
    EXPECT_EQ(1, s.size_());
}

TEST(mStack, can_resize_stack)
{
    mStack<int> s;
    s.resize(8);
    EXPECT_EQ(8, s.size_());
}

TEST(mStack, can_get_top_element)
{
    mStack<int> s;
    s.push(6);
    s.push(7);
    EXPECT_EQ(7, s.top());
}

TEST(mStack, can_resize_stack_while_pushing_elemets)
{
    mStack<int> s;
    s.push(6);
    s.push(7);
    EXPECT_EQ(6, s.capacity_());
}
