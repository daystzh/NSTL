//
// Created by daystzh on 17/12/2022.
//

#ifndef TINYSTL_STRING_H
#define TINYSTL_NTD_STRING_H
#include <cstddef>
#include <cstring>
#include "algorithm/iterator.h"
namespace nstd {
class string {
 public:
  using Iterator = nstd::iterator<string, char>;

  string(const char *str = "") {
    size_ = strlen(str);
    cap_ = size_ + 1;
    data_ = new char[cap_];
    memcpy(data_, str, size_);
    data_[size_] = 0;
  }

  string(const string &str) {
    size_ = str.size_;
    cap_ = str.cap_;
    data_ = new char[size_ + 1];
    memcpy(data_, str.data_, size_ + 1);
  }

  string(string &&str) {
    size_ = str.size_;
    cap_ = str.cap_;
    data_ = str.data_;
    str.data_ = nullptr;
  }

  ~string() { delete data_; }

  Iterator begin() { return Iterator(this); }

  Iterator end() { return Iterator(this, size_); }

  void append(Iterator begin_iter, Iterator end_iter) {
    size_t size = (&*end_iter - &*begin_iter);
    if (cap_ < size_ + 1 + size) {
      size_t n_cap = 2 * cap_;
      n_cap = n_cap < size_ + size + 1 ? size_ + size + 1 : n_cap;
      resize(n_cap);
    }
    memcpy(data_ + size_, &*begin_iter, size);
    size_ += size;
    data_[size_] = 0;
  }

  char &operator[](size_t index) { return data_[index]; }

  size_t size() { return size_; }

 private:
  void resize(size_t cap) {
    char *n_data = new char[cap];
    memcpy(n_data, data_, size_ + 1);
    delete data_;
    data_ = n_data;
    cap_ = cap;
  }

 private:
  char *data_;
  size_t size_;
  size_t cap_;
};
}  // namespace nstd
#endif  // TINYSTL_STRING_H
