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