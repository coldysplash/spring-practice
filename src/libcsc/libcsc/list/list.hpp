#pragma once

#include <iterator>
#include <utility>

template <typename T> struct Node {
  T value_;
  Node<T> *next_ = nullptr;
  Node<T> *prev_ = nullptr;

  Node(const T &item) : value_(item) {}
};

namespace list {

template <typename T> class List {
private:
  Node<T> *head_ = nullptr;
  Node<T> *tail_ = nullptr;
  size_t size_ = 0;

public:
  // Iterator
  template <typename U> class Iterator {
  public:
    explicit Iterator(Node<T> *node) : node_(node) {}
    auto &operator++() noexcept {
      node_ = node_->next_;
      return *this;
    }
    auto operator++(int) noexcept {
      auto temp = *this;
      ++(*this);
      return temp;
    }
    auto &operator--() noexcept {
      node_ = node_->next_;
      return *this;
    }
    auto operator--(int) noexcept {
      auto temp = *this;
      --(*this);
      return temp;
    }

    T &operator*() const noexcept { return node_->value_; }
    T *operator->() const noexcept { return &node_->value; }

    friend bool operator==(const Iterator<U> &lhs, const Iterator<U> &rhs) {
      return lhs.node_ == rhs.node_;
    }
    friend bool operator!=(const Iterator<U> &lhs, const Iterator<U> &rhs) {
      return !(lhs == rhs);
    }

  private:
    Node<T> *node_;
  };

  using iterator = Iterator<T>;
  using const_iterator = Iterator<const T>;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  List() = default;
  // List(Iterator begin, Iterator end);
  List(const std::initializer_list<T> &init_list);
  // List(const List &copy_list);
  // List(List &&move_copy_list);
  // List operator=(const List &copy_list);
  // List operator=(List &&move_copy_list);
  ~List();

  iterator begin() const noexcept { return iterator(head_); }
  iterator end() const noexcept { return iterator(tail_->next_); }

  // T &front();
  // T &back();

  void push_back(T value);
  void clear();
};

/* constructor with initializer_list */
template <typename T>
List<T>::List(const std::initializer_list<T> &init_list)
    : size_(init_list.size()) {

  for (const auto &item : init_list) {
    push_back(item);
  }
}

template <typename T> void List<T>::push_back(T value) {
  if (head_ == nullptr) {
    head_ = tail_ = new Node<T>(value);
    head_->prev_ = nullptr;
    tail_->next_ = nullptr;
  } else {
    tail_->next_ = new Node<T>(value);
    tail_ = tail_->next_;
  }
}

template <typename T> void List<T>::clear() {
  while (head_ != nullptr) {
    delete std::exchange(head_, head_->next_);
  }
  head_ = tail_ = nullptr;
  size_ = 0;
}

template <typename T> List<T>::~List() { clear(); }

} // namespace list