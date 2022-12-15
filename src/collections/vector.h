//
// Created by daystzh on 12/12/2022.
//
#include <cstddef>
#ifndef TINYSTL_VECTOR_H
#define TINYSTL_VECTOR_H
namespace nstd {
template <typename T>
class vector {
 private:
  T *data_;
  size_t size_;
  size_t cap_;

 public:
  void push_back(const T &val) {
    if (size_ == cap_) {
      resize();
    }
    data_[size_++] = val;
  }

  void reserve(int num) {
    if (num <= cap_) {
      return;
    }
    resize(num);
  }

  void push_back(T &&val) {
    if (size_ == cap_) {
      resize();
    }
    data_[size_++] = val;
  }

  size_t size() { return size_; }

  size_t cap() { return cap_; }
  void pop_back() { size_--; }

  ~vector() { delete data_; }

  explicit vector(size_t size, T &&val) : size_(size), cap_(size) {
    data_ = new T[cap_];
    for (int i = 0; i < size_; i++) {
      data_[i] = val;
    }
  }

  explicit vector() : size_(0), cap_(8) { data_ = new T[cap_]; }

  T &operator[](size_t index) { return data_[index]; }

 private:
  void resize() { resize(cap_ * 2); }

  void resize(int num) {
    cap_ = num;
    T *tmp = new T[num];
    for (int i = 0; i < size_; i++) {
      tmp[i] = data_[i];
    }
    delete[] data_;
    data_ = tmp;
  }
};
}  // namespace nstd

#endif  // TINYSTL_VECTOR_H
