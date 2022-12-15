//
// Created by daystzh on 12/12/2022.
//

#include "collections/vector.h"
#include <iostream>
#include "gtest/gtest.h"

TEST(vectorTest, testSquareBrackets) {
  nstd::vector<int> vec(10, 0);
  for (int i = 0; i < 10; i++) {
    vec[i] = i;
  }
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(vec[i], i);
  }
}

TEST(vectorTest, testPushBack) {
  nstd::vector<int> vec;
  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
  }
  EXPECT_EQ(vec.size(), 10);
  EXPECT_EQ(vec.cap(), 16);
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(vec[i], i);
  }
}

TEST(vectorTest, testPopBack) {
  nstd::vector<int> vec;
  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
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

TEST(vectorTest, test_class) {
  nstd::vector<int> vec;
  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
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