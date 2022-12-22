//
// Created by daystzh on 17/12/2022.
//

#ifndef TINYSTL_STRING_H
#define TINYSTL_NTD_STRING_H
#include <cstddef>
#include <cstring>
namespace nstd {
class string {
 public:
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

  char &operator[](size_t index) { return data_[index]; }

  size_t size() { return size_; }

 private:
  char *data_;
  size_t size_;
  size_t cap_;
};
}  // namespace nstd
#endif  // TINYSTL_STRING_H
