#include "mQueue2Stacks.h"
#include "gtest.h"

TEST(mQueue2Stacks, can_create_mQueue2Stacks)
{
    ASSERT_NO_THROW(mQueue2Stacks<int> qs);
}

TEST(mQueue2Stacks, can_check_for_empty)
{
    mQueue2Stacks<int> qs;
    EXPECT_EQ(1, qs.isEmpty());
}

TEST(mQueue2Stacks, can_check_for_full)
{
    mQueue2Stacks<int> qs;
    EXPECT_NE(1, qs.isFull());
}

TEST(mQueue2Stacks, can_return_correct_size)
{
    mQueue2Stacks<int> qs;
    qs.push(1); qs.push(1); qs.push(1); qs.push(1); qs.push(1);
    EXPECT_EQ(5, qs.size_());
}

TEST(mQueue2Stacks, can_return_correct_capacity)
{
    mQueue2Stacks<int> qs;
    qs.push(1); qs.push(1); qs.push(1); qs.push(1); qs.push(1);
    EXPECT_EQ(2 * 3 + 2, qs.capacity_());
}

TEST(mQueue2Stacks, can_push_element)
{
    mQueue2Stacks<int> qs;
    qs.push(1);
    EXPECT_EQ(1, qs.front());
}

TEST(mQueue2Stacks, can_pop_element)
{
    mQueue2Stacks<int> qs;
    qs.push(6);
    qs.push(6);
    qs.pop();
    EXPECT_EQ(2, qs.size_());
}


