#include "mQueue.h"
#include "gtest.h"

TEST(mQueue, can_create_mQueue)
{
    ASSERT_NO_THROW(mQueue<int> q);
}

TEST(mQueue, can_check_for_empty)
{
    mQueue<int> q;
    EXPECT_EQ(1, q.isEmpty());
}

TEST(mQueue, can_check_for_full)
{
    mQueue<int> q;
    EXPECT_NE(1, q.isFull());
}

TEST(mQueue, can_return_correct_size)
{
    mQueue<int> q;
    q.push(1); q.push(1); q.push(1); q.push(1); q.push(1);
    EXPECT_EQ(5, q.size_());
}

TEST(mQueue, can_return_correct_capacity)
{
    mQueue<int> q;
    q.push(1); q.push(1); q.push(1); q.push(1); q.push(1);
    EXPECT_EQ(2 * 2 + 2, q.capacity_());
}

TEST(mQueue, can_push_element)
{
    mQueue<int> s;
    s.push(1);
    EXPECT_EQ(1, s.get_back());
}

TEST(mQueue, can_pop_element)
{
    mQueue<int> s;
    s.push(6);
    s.push(9);
    s.pop();
    EXPECT_EQ(1, s.size_());
}

TEST(mQueue, can_get_front_element)
{
    mQueue<int> s;
    s.push(6);
    s.push(9);
    EXPECT_EQ(6, s.get_front());
}

TEST(mQueue, can_get_back_element)
{
    mQueue<int> s;
    s.push(6);
    s.push(9);
    EXPECT_EQ(9, s.get_back());
}

TEST(mQueue, can_move_back_element_before_front)
{
    mQueue<int> s;
    s.push(6);
    s.push(9);
    s.pop();
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    EXPECT_EQ(0, s.get_back_ind());
}