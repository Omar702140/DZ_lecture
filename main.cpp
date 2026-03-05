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

int main() {
  Node<int>* head = nullptr;
  std::cout << "empty=" << std::boolalpha << isEmpty(head) << "\n";
  clearList(head);
  return 0;
}
