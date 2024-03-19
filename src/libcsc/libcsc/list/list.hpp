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

  /* default constructor */
  List() = default;

  /* constructor with initializer_list */
  List(const std::initializer_list<T> &init_list) {
    for (const auto &item : init_list) {
      push_back(item);
    }
  }

  /* constructor with iterators */
  List(iterator begin, iterator end) {
    for (auto it = begin; it != end; it++) {
      push_back(*it);
    }
  }

  /* Copy constructor */
  List(const List &other_list) {
    for (const auto &item : other_list) {
      push_back(item);
    }
  }

  /* Move constructor */
  List(List &&other_list) {
    std::swap(head_, other_list.head_);
    std::swap(tail_, other_list.tail_);
    std::swap(size_, other_list.size_);
    other_list.head_ = other_list.tail_ = nullptr;
    other_list.size_ = 0;
  }

  /* Copy assignment operator */
  List &operator=(const List &other_list) {
    if (this != other_list) {
      for (const auto &item : other_list) {
        push_back(item);
      }
    }
    return *this;
  }
  /* Move assignment operator */
  List &operator=(List &&other_list) {
    if (this == &other_list) {
      return *this;
    }
    std::swap(head_, other_list.head_);
    std::swap(tail_, other_list.tail_);
    std::swap(size_, other_list.size_);

    other_list.head_ = other_list.tail_ = nullptr;
    other_list.size_ = 0;

    return *this;
  };

  /* Destructor */
  ~List() { clear(); }

  T &front() { return head_->value_; }
  T &back() { return tail_->value_; }

  /* push_back */
  void push_back(T value) {
    if (head_ == nullptr) {
      head_ = tail_ = new Node<T>(value);
      ++size_;
    } else {
      tail_->next_ = new Node<T>(value);
      tail_ = tail_->next_;
      ++size_;
    }
  }

  /* push_front */
  void push_front(T value) {
    if (head_ == nullptr) {
      head_ = tail_ = new Node<T>(value);
      ++size_;
    } else {
      Node<T> *new_node = new Node<T>(value);
      Node<T> *temp = head_;
      head_ = new_node;
      head_->next_ = temp;
      temp->prev_ = head_;
      ++size_;
    }
  }

  /* size */
  size_t size() const noexcept { return size_; }

  /* empty */
  bool empty() const noexcept { return (head_ == nullptr); }

  /* clear */
  void clear() noexcept {
    while (head_ != nullptr) {
      delete std::exchange(head_, head_->next_);
    }
    head_ = tail_ = nullptr;
    size_ = 0;
  }
};

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

template <typename T>
bool operator!=(const List<T> &lhs, const List<T> &rhs) noexcept {
  return !(lhs == rhs);
}

} // namespace list