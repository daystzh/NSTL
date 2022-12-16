//
// Created by daystzh on 12/12/2022.
//

#include "collections/vector.h"
// #include <iostream>
#include <exception>
#include "gtest/gtest.h"
#include "simple_test_class.h"

// #define USE_STL_ 1
#ifdef USE_STL_
template <typename T>
using vector_t = std::vector<T>;
#else
template <typename T>
using vector_t = nstd::vector<T>;
#endif

TEST(VectorTest, Basic) {
  vector_t<int> vec(10, 0);
  EXPECT_EQ(vec.size(), 10);
  EXPECT_GE(vec.capacity(), vec.size());
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(vec[i], 0);
  }
}

TEST(VectorTest, SubscriptOperation) {
  vector_t<int> vec(10, 0);
  for (int i = 0; i < 10; i++) {
    vec[i] = i;
  }
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(vec[i], i);
  }
}

TEST(VectorTest, PushBackInt) {
  vector_t<int> vec;
  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
    EXPECT_GE(vec.capacity(), vec.size());
  }
  EXPECT_EQ(vec.size(), 10);
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(vec[i], i);
  }
}

TEST(VectorTest, PopBackInt) {
  vector_t<int> vec;
  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
    EXPECT_GE(vec.capacity(), vec.size());
  }
  EXPECT_EQ(vec.size(), 10);
  for (int i = 0; i < 5; i++) {
    vec.pop_back();
    EXPECT_EQ(vec.size(), 10 - i - 1);
  }

  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(vec[i], i);
  }
}

TEST(VectorTest, EmplaceBackOperation) {
  vector_t<A> vec;
  for (int i = 0; i < 10; i++) {
    vec.emplace_back(i);
    EXPECT_GE(vec.capacity(), vec.size());
  }
  EXPECT_EQ(vec.size(), 10);
  for (int i = 0; i < 5; i++) {
    vec.pop_back();
    EXPECT_EQ(vec.size(), 9 - i);
  }

  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(vec[i].get_x(), i);
  }
}

TEST(VectorTest, ReserveFunction) {
  //  nstd::vector<A> vec;
  vector_t<A> vec;
  vec.reserve(0);
  EXPECT_EQ(vec.capacity(), 0);
  vec.reserve(10);
  EXPECT_EQ(vec.capacity(), 10);
  vec.reserve(7);
  EXPECT_EQ(vec.capacity(), 10);
  vec.reserve(11);
  EXPECT_EQ(vec.capacity(), 11);
}

TEST(VectorTest, AtFunction) {
  //  nstd::vector<A> vec;
  vector_t<int> vec(10, 0);
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(vec.at(i), 0);
    vec.at(i) = i;
    EXPECT_EQ(vec.at(i), i);
  }
}

TEST(VectorTest, AtFunctionOutOfRange) {
  //  nstd::vector<A> vec;
  vector_t<int> vec(10, 0);

  try {
    vec.at(10);
  } catch (std::out_of_range &e) {
    EXPECT_STREQ(e.what(), "vector");
  }
}