//
// Created by daystzh on 12/12/2022.
//
#include "gcd.h"
namespace my_stl {
int gcd(int x, int y) {
  while (x % y != 0) {
    int z = x % y;
    x = y;
    y = z;
  }
  return y;
}
}  // namespace my_stl