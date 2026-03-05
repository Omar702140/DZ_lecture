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

int main() {
  Node<int>* head = nullptr;
  std::cout << "\n";
  clearList(head);
  return 0;
}
