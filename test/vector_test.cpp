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

TEST(VectorTest, moveConstruct) {
  vector_t<int> vec(vector_t<int>(10, 2));
  EXPECT_EQ(vec.size(), 10);
  for (int i = 0; i < vec.size(); i++) {
    EXPECT_EQ(vec[i], 2);
  }
}

TEST(VectorTest, moveOperator) {
  vector_t<int> vec;
  vec = (vector_t<int>(10, 2));
  EXPECT_EQ(vec.size(), 10);
  for (int i = 0; i < vec.size(); i++) {
    EXPECT_EQ(vec[i], 2);
  }
}

TEST(VectorTest, copyConstruct) {
  vector_t<int> tmp(10, 2);
  vector_t<int> vec(tmp);
  EXPECT_EQ(vec.size(), 10);
  for (int i = 0; i < vec.size(); i++) {
    EXPECT_EQ(vec[i], 2);
  }
}

TEST(VectorTest, copyOperator) {
  vector_t<int> tmp(10, 2);
  vector_t<int> vec;
  vec = tmp;
  EXPECT_EQ(vec.size(), 10);
  for (int i = 0; i < vec.size(); i++) {
    EXPECT_EQ(vec[i], 2);
  }
  vec = vec;
  EXPECT_EQ(vec.size(), 10);
  for (int i = 0; i < vec.size(); i++) {
    EXPECT_EQ(vec[i], 2);
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

TEST(VectorTest, IteratorTest) {
  vector_t<int> vec(10, 1);
  vector_t<int>::Iterator iter = vec.begin();
  iter.print();
  while (iter != vec.end()) {
    EXPECT_EQ(*iter, 1);
    //    iter.operator++();
    iter++;
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

  for (int i = 0; i < 5; i++) {
    vec.pop_back();
  }

  for (int i = 0; i < 10; i++) {
    vec.emplace_back(i, 2 * i);
    EXPECT_GE(vec.capacity(), vec.size());
  }

  EXPECT_EQ(vec.size(), 10);
  for (int i = 0; i < 5; i++) {
    vec.pop_back();
    EXPECT_EQ(vec.size(), 9 - i);
  }

  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(vec[i].get_x(), i);
    EXPECT_EQ(vec[i].get_y(), i * 2);
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

TEST(VectorTest, reaverse) {
  vector_t<int> vec1;
  for (size_t i = 0; i < 20; i++) {
    vec1.emplace_back(i + 1);
  }
  EXPECT_EQ(vec1.size(), 20);
  for (size_t i = 0; i < 20; i++) {
    EXPECT_EQ(vec1[i], i + 1);
  }
  vec1.reverse();
  EXPECT_EQ(vec1.size(), 20);
  for (size_t i = 0; i < 20; i++) {
    EXPECT_EQ(vec1[i], 20 - i);
  }

  vector_t<A> vec2;
  for (size_t i = 0; i < 20; i++) {
    vec2.emplace_back(i + 1);
  }
  EXPECT_EQ(vec2.size(), 20);
  for (size_t i = 0; i < 20; i++) {
    EXPECT_EQ(vec2[i], A(i + 1));
  }
  std::cout << "-------------" << (vec2[0] == A(0)) << std::endl;
  vec2.reverse();
  EXPECT_EQ(vec2.size(), 20);
  for (size_t i = 0; i < 20; i++) {
    EXPECT_EQ(vec2[i], A(20 - i));
  }
}

TEST(VecrorTest, remove) {
  vector_t<A> vec;
  for (size_t i = 0; i < 10; i++) {
    vec.emplace_back(i + 1, 1);
  }
  auto iter = vec.begin();
  iter = vec.erase(iter);
  EXPECT_EQ(*iter, A(2, 1));
  EXPECT_EQ(vec.size(), 9);
  for (size_t i = 0; i < 9; i++) {
    EXPECT_EQ(vec[i], A(i + 2, 1));
  }
  iter++;
  for (size_t i = 0; i < 8; i++) {
    iter = vec.erase(iter);
  }
  EXPECT_EQ(vec.size(), 1);
  EXPECT_TRUE(vec.end() == iter);
  EXPECT_EQ(vec[0], A(2, 1));
}
