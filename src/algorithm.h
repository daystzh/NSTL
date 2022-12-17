//
// Created by daystzh on 17/12/2022.
//

#ifndef TINYSTL_ALGORITHM_H
#define TINYSTL_ALGORITHM_H
namespace nstd {

template <typename T>
void swap(T &lhs, T &rhs) {
  T tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

}  // namespace nstd

#endif  // TINYSTL_ALGORITHM_H
