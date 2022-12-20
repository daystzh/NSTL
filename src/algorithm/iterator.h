//
// Created by daystzh on 20/12/2022.
//

#ifndef TINYSTL_ITERATOR_H
#define TINYSTL_ITERATOR_H
namespace nstd {

template <typename container_type, typename type>
class iterator {
 public:
  explicit iterator(container_type *container) : container_(container), index_(0) {}
  explicit iterator(container_type *container, size_t n) : container_(container), index_(n) {}

  type &operator*() { return container_[index_]; }
  container_type &operator++() {
    index_++;
    return *this;
  }
  container_type &operator--() {
    index_--;
    return *this;
  }

  bool operator==(const iterator &other) { return container_ == other.container_ && index_ == other.index_; }

  bool operator!=(const iterator &other) { return !operator==(other); }

 private:
  container_type *container_;
  size_t index_;
};
}  // namespace nstd
#endif  // TINYSTL_ITERATOR_H
