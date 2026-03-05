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
  delete head;
  head = nullptr;
}

template <class T>
void pushBack(Node<T>*& head, const T& value) {
  Node<T>* n = new Node<T>{value, nullptr, nullptr};
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
}

int main() {
  Node<int>* head = nullptr;
  std::cout << "\n";
  clearList(head);
  return 0;
}
