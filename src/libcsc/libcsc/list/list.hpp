#include <iostream>

template <typename T> struct Node {
  T value_;
  Node<T> *next_ = nullptr;
  Node<T> *prev_ = nullptr;

  Node(const T &item) : value_(item) {}
};

namespace list {

template <typename T> class List {
private:
  List<T> *head_ = nullptr;
  List<T> *tail_ = nullptr;
  size_t size_ = 0;

public:
  List() = default;
};

} // namespace list