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
  
}

int main() {
    Node<int>* head = nullptr;
    std::cout << "empty=" << std::boolalpha << isEmpty(head) << "\n";
    return 0;
}
