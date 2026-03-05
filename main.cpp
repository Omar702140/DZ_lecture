#include <iostream>

template <class T>
struct Node {
  T val;
  Node* next;
  Node* prev;
};

template <class T>
bool isEmpty(Node<T>* head) {
  return head == nullptr;
}

template <class T>
void clearList(Node<T>*& head) {
  if (!head) {
    return;
  }
  Node<T>* cur = head->next;
  while (cur != head) {
      Node<T>* toDel = cur;
      cur = cur->next;
      delete toDel;
  }
  //T::~T()
  delete head;
  head = nullptr;
}

template <class T>
void pushBack(Node<T>*& head, const T& value) {
  Node<T>* n = new Node<T>{value, nullptr, nullptr};
  //T::T(const T&) (копирующий конструктор)
  if (!head) {
    n->next = n;
    n->prev = n;
    head = n;
    return;
  }
  Node<T>* tail = head->prev;
  n->next = head;
  n->prev = tail;
  tail->next = n;
  head->prev = n;
}

template <class T>
T& front(Node<T>* head) {
  if (!head) {
    throw std::out_of_range("front(): empty");
  }
  return head->val;
}

template <class T>
T& back(Node<T>* head) {
  if (!head) {
    throw std::out_of_range("back(): empty");
  }
  return head->prev->val;
}

template <class T>
void popFront(Node<T>*& head) {
  if (!head) {
    throw std::out_of_range("popFront(): empty");
  }
  if (head->next == head) {
    delete head;
    head = nullptr;
    return;
  }
  Node<T>* tail = head->prev;
  Node<T>* oldHead = head;
  Node<T>* newHead = head->next;
  tail->next = newHead;
  newHead->prev = tail;
  head = newHead;
  delete oldHead;
  //T::~T()
}

template <class T>
void popBack(Node<T>*& head) {
  if (!head) {
    throw std::out_of_range("popBack(): empty");
  }
  if (head->next == head) {
    delete head;
    head = nullptr;
    return;
  }
  Node<T>* tail = head->prev;
  Node<T>* newTail = tail->prev;
  newTail->next = head;
  head->prev = newTail;
  delete tail;
  //T::~T()
}

template <class T>
struct Iter {
  Node<T>* head;
  Node<T>* cur;
  bool started;
};

template <class T>
Iter<T> iterBegin(Node<T>* head) {
  if (!head)  {
    return Iter<T>{nullptr, nullptr, true};
  }
  return Iter<T>{head, head, true};
}

template <class T>
bool iterIsEnd(const Iter<T>& it) {
  return it.cur == nullptr;
}

template <class T>
T& iterGet(Iter<T>& it) {
  if (!it.cur) {
    throw std::out_of_range("iterGet(): end");
  }
  return it.cur->val;
}

template <class T>
void iterNext(Iter<T>& it) {
  if (!it.cur) {
    return;
  }
  it.cur = it.cur->next;
  if (it.cur == it.head) {
    it.cur = nullptr;
  }
}

int main() {
  int a[] = {1, 2, 3, 4};
  const int n = sizeof(a) / sizeof(a[0]);
  Node<int>* head = nullptr;
  for (int i = 0; i < n; ++i) {
    pushBack(head, a[i]);
  }
  Iter<int> it = iterBegin(head);
  while (!iterIsEnd(it)) {
    std::cout << iterGet(it) << " ";
    iterNext(it);
  }
  std::cout << "\n";
  clearList(head);
}
