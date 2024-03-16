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
  List(const std::initializer_list<T> &init_list);
  List(iterator begin, iterator end);
  // List(const List &copy_list);
  // List(List &&move_copy_list);
  // List operator=(const List &copy_list);
  // List operator=(List &&move_copy_list);
  ~List();

  iterator begin() const noexcept { return iterator(head_); }
  iterator end() const noexcept { return iterator(tail_->next_); }
  const_iterator cbegin() const noexcept { return const_iterator(head_); }
  const_iterator cend() const noexcept { return const_iterator(tail_->next_); }
  reverse_iterator rbegin() const noexcept { return reverse_iterator(end()); }
  reverse_iterator rend() const noexcept { return reverse_iterator(begin()); }
  const_reverse_iterator crbegin() const noexcept {
    return const_reverse_iterator(cend());
  }
  const_reverse_iterator crend() const noexcept {
    return const_reverse_iterator(cbegin());
  }

  T &front();
  T &back();
  void push_back(T value);
  void push_front(T value);

  size_t size() const noexcept { return size_; }
  bool empty() const noexcept;
  void clear();
};

/* constructor with initializer_list */
template <typename T> List<T>::List(const std::initializer_list<T> &init_list) {
  for (const auto &item : init_list) {
    push_back(item);
  }
}

/* constructor with iterators */
template <typename T> List<T>::List(iterator begin, iterator end) {
  for (auto it = begin; it != end; it++) {
    push_back(*it);
  }
}

template <typename T> T &List<T>::front() { return head_->value_; }
template <typename T> T &List<T>::back() { return tail_->value_; }

template <typename T> void List<T>::push_back(T value) {
  if (head_ == nullptr) {
    head_ = tail_ = new Node<T>(value);
    ++size_;
  } else {
    tail_->next_ = new Node<T>(value);
    tail_ = tail_->next_;
    ++size_;
  }
}

template <typename T> void List<T>::push_front(T value) {
  if (head_ == nullptr) {
    head_ = tail_ = new Node<T>(value);
    ++size_;
  } else {
    auto new_node = new Node<T>(value);
    head_->prev_ = new_node;
    head_ = new_node;
    ++size_;
  }
}

template <typename T> bool List<T>::empty() const noexcept {
  return (head_ == nullptr);
}

template <typename T>
bool operator==(const List<T> &lhs, const List<T> &rhs) noexcept {
  auto first1 = lhs.begin();
  auto first2 = rhs.begin();
  auto last1 = lhs.end();
  for (; first1 != last1; ++first1, ++first2) {
    if (!(*first1 == *first2)) {
      return false;
    }
    return true;
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