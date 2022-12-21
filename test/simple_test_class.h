//
// Created by daystzh on 12/12/2022.
//

#ifndef TINYSTL_SIMPLE_TEST_CLASS_H
#define TINYSTL_SIMPLE_TEST_CLASS_H
#include "iostream"
class A {
 public:
  A(int x) : x_(x) {
    //    std::cout << "A construct x:" << x_ << std::endl;
  }
  A(int x, int y) : x_(x), y_(y) {}
  ~A() {
    //    std::cout << "A deconstruct x:" << x_ << std::endl;
  }
  void set_x(int x) { x_ = x; }
  int get_x() { return x_; }
  int get_y() { return y_; }
  A(A &&) = default;
  A &operator=(A &&) = default;

  A(const A &) = default;
  A &operator=(const A &) = default;
  bool operator==(const A &other) const { return x_ == other.x_ && y_ == other.y_; }

 private:
  int x_;
  int y_ = 0;
};
#endif  // TINYSTL_SIMPLE_TEST_CLASS_H
