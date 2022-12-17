//
// Created by daystzh on 12/12/2022.
//

#include "collections/vector.h"
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
  vector_t<int> empty_vec;
  EXPECT_TRUE(empty_vec.empty());

  vector_t<int> vec(10, 0);
  EXPECT_FALSE(vec.empty());
  EXPECT_EQ(vec.size(), 10);
  EXPECT_GE(vec.capacity(), vec.size());
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(vec[i], 0);
  }
  for (int i = 0; i < 10; i++) {
    vec[i] = i + 1;
  }

  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(vec[i], i + 1);
  }
  EXPECT_EQ(vec.front(), 1);
  EXPECT_EQ(vec.back(), 10);
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

TEST(VectorTest, ShrinkToFit) {
  vector_t<int> vec;
  int i;
  for (i = 0; i < 10; i++) {
    vec.push_back(i);
    if (vec.size() < vec.capacity()) {
      break;
    }
  }
  EXPECT_GT(vec.capacity(), vec.size());
  vec.shrink_to_fit();
  EXPECT_EQ(vec.size(), i + 1);
  EXPECT_EQ(vec.capacity(), vec.size());
}

TEST(VectorTest, EqualOperator) {
  vector_t<int> vec1;
  vector_t<int> vec2;
  //  std::cout << vec1.max_size() << std::endl;
  EXPECT_TRUE(vec1 == vec2);
  EXPECT_FALSE(vec1 != vec2);
  for (size_t i = 0; i < 10; i++) {
    vec1.push_back(i);
    vec2.push_back(i);
  }
  EXPECT_TRUE(vec1 == vec2);
  vec1.reserve(vec1.size());
  EXPECT_TRUE(vec1 == vec2);
  vec1.pop_back();
  EXPECT_FALSE(vec1 == vec2);
  EXPECT_TRUE(vec1 != vec2);

  vec2.pop_back();
  EXPECT_TRUE(vec1 == vec2);
  vec1[0] = 1;
  EXPECT_FALSE(vec1 == vec2);
}

TEST(VectorTest, GetMaxSize) {
  std::vector<int> vec1;
  nstd::vector<int> vec2;
  EXPECT_TRUE(vec1.max_size() == vec2.max_size());
}

TEST(VectorTest, SwapFunction) {
  vector_t<int> vec1(10, 1);
  vector_t<int> vec2(5, 2);
  EXPECT_EQ(vec1.size(), 10);
  for (int i = 0; i < vec1.size(); i++) {
    EXPECT_EQ(vec1[i], 1);
  }
  EXPECT_EQ(vec2.size(), 5);
  for (int i = 0; i < vec2.size(); i++) {
    EXPECT_EQ(vec2[i], 2);
  }
  vec1.swap(vec2);

  EXPECT_EQ(vec1.size(), 5);
  for (int i = 0; i < vec1.size(); i++) {
    EXPECT_EQ(vec1[i], 2);
  }
  EXPECT_EQ(vec2.size(), 10);
  for (int i = 0; i < vec2.size(); i++) {
    EXPECT_EQ(vec2[i], 1);
  }
}
