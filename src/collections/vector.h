//
// Created by daystzh on 12/12/2022.
//

#ifndef TINYSTL_VECTOR_H
#define TINYSTL_VECTOR_H
#include <cstddef>
#include <exception>
#include <memory>
#include "../algorithm.h"

namespace nstd {
template <typename T, typename Allocate = std::allocator<T> >
class vector {
 private:
  T *data_ = nullptr;
  size_t size_;
  size_t cap_;
  Allocate allocator_;

 public:
  void push_back(const T &val) {
    if (size_ == cap_) {
      resize();
    }
    data_[size_++] = val;
  }

  void reserve(size_t num) {
    if (num <= cap_) {
      return;
    }
    resize(num);
  }

  void shrink_to_fit() {
    if (cap_ > size_) {
      resize(size_);
    }
  }

  void push_back(T &&val) {
    if (size_ == cap_) {
      resize();
    }
    data_[size_++] = std::move(val);
  }

  template <class val_type>
  void emplace_back(val_type &&val) {
    if (size_ == cap_) {
      resize();
    }
    construct_at_end(std::forward<val_type>(val));
    size_++;
  }
  size_t size() const { return size_; }

  size_t capacity() { return cap_; }

  T &at(size_t index) {
    if (index >= size_) {
      throw std::out_of_range("vector");
    }
    return data_[index];
  }

  void pop_back() {
    size_--;
    data_[size_].~T();
  }

  ~vector() {
    for (size_t i = 0; i < size_; i++) {
      data_[i].~T();
    }
    if (cap_ > 0) {
      allocator_.deallocate(data_, cap_);
    }
  }

  explicit vector(size_t size, T &&val) : size_(size), cap_(size) {
    data_ = new T[cap_];
    for (size_t i = 0; i < size_; i++) {
      data_[i] = val;
    }
  }

  vector() : size_(0), cap_(0) {}

  T &operator[](size_t index) { return data_[index]; }

  const T &operator[](size_t index) const { return data_[index]; }

  bool operator==(const vector &other) {
    if (size_ != other.size()) {
      return false;
    }

    for (size_t i = 0; i < size_; i++) {
      if (!(data_[i] == other[i])) {
        return false;
      }
    }
    return true;
  }

  T &back() { return data_[size_ - 1]; }

  T &front() { return data_[0]; }

  bool operator!=(const vector &other) { return !this->operator==(other); }

  void swap(vector &other) {
    //    swap(data_, other.data_);
    //    swap(size_, other.size_);
    //    swap(cap_, other.cap_);
    using nstd::swap;
    swap(data_, other.data_);
    swap(size_, other.size_);
    swap(cap_, other.cap_);
  }

  size_t max_size() {
    //      return 100;
    return size_t(-1) / sizeof(T);
  }

  bool empty() { return size_ == 0; }

 private:
  void resize() {
    auto new_cap = cap_ ? cap_ * 2 : 1;
    resize(new_cap);
  }

  void resize(size_t num) {
    //    T *tmp = new T[num];
    T *tmp = allocator_.allocate(num);
    for (size_t i = 0; i < size_; i++) {
      tmp[i] = data_[i];
      data_[i].~T();
    }

    if (cap_ > 0) {
      allocator_.deallocate(data_, cap_);
    }
    cap_ = num;
    data_ = tmp;
  }

  template <class val_type>
  void construct_at_end(val_type &&val) {
    new (data_ + size_) T(std::forward<val_type>(val));
  }
};
}  // namespace nstd

#endif  // TINYSTL_VECTOR_H
