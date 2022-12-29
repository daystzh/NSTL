//
// Created by daystzh on 22/12/2022.
//
#include "gtest/gtest.h"
#include "ntd_string.h"
#include "simple_test_class.h"
using string_t = nstd::string;

TEST(StringTest, Basic) {
  const char *str_test = "string_test";
  string_t str("string_test");
  EXPECT_EQ(str.size(), strlen(str_test));
  for (size_t i = 0; i < str.size(); i++) {
    EXPECT_EQ(str[i], str_test[i]);
  }
}

TEST(StringTest, append) {
  const char *str_test = "string_teststring_test";
  string_t str1("string_test");
  string_t str2("string_test");
  str1.append(str2.begin(), str2.end());
  EXPECT_EQ(str1.size(), strlen(str_test));
  for (size_t i = 0; i < str1.size(); i++) {
    EXPECT_EQ(str1[i], str_test[i]);
  }
}