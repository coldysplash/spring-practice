#include <iostream>
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
  List();
  // List(Iterator begin, Iterator end);
  List(const std::initializer_list<T> &init_list);
  // List(const List &copy_list);
  // List(List &&move_copy_list);
  // List operator=(const List &copy_list);
  // List operator=(List &&move_copy_list);
  ~List();

  void clear();
};

template <typename T>
List<T>::List() : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
List<T>::List(const std::initializer_list<T> &init_list)
    : head_(nullptr), tail_(nullptr), size_(init_list.size()) {

  if (init_list.size() != 0) {
    Node<T> *new_node = new Node(*init_list.begin());
    head_ = tail_ = new_node;

    for (auto it = init_list.begin() + 1; it != init_list.end(); it++) {
      Node<T> *prev_node = new_node;
      new_node = new Node<T>(*it);
      tail_->next_ = new_node;
      tail_->prev_ = prev_node;
      tail_ = new_node;
    }
  }
}

template <typename T> void List<T>::clear() {
  while (head_ != nullptr) {
    Node<T> *deletable = std::exchange(head_, head_->next_);
  }
}

template <typename T> List<T>::~List() { clear(); }

} // namespace list