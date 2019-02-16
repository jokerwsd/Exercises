#ifndef _BI_TREE_H_
#define _BI_TREE_H_

#include <algorithm>
#include <iostream>
using namespace std;

enum class tree_order { PRE_ORDER, IN_ORDER, POS_ORDER };

template <class T>
class Node {
 public:
  T m_data;
  Node<T>* m_left;
  Node<T>* m_right;
  Node<T>(const T& d) : m_data(d), m_left(nullptr), m_right(nullptr) {}
  /*Note: = delete means that the compiler will not
    generate those constructors for you.
    this is only allowed on copy constructor and assignment operator.
   */

  Node<T>& operator=(const Node<T>&) = delete;
};

template <class T>
class BiTree {
public:
  BiTree();
  ~BiTree() { delete[] m_root; }
  void add_node(const T& val);
  void insert(const T& val, Node<T>*& parent);
  bool find(const T& val, Node<T>* parent);
  bool is_empty();
  void print_tree(tree_order print_order);
  int get_height(Node<T>* parent = nullptr);
private:
  Node<T>* m_root;
};

template <class T>
BiTree<T>::BiTree() : m_root(nullptr){
}

template <class T>
void BiTree<T>::insert(const T& val, Node<T>*& parent) {
  if (parent == nullptr) {
    cout << "insert data!" << endl;
    parent = new Node<T>(val);
    return;
  }
  if (val == (parent)->m_data) {
    cout << "data already exsit!" << endl;
    return;
  } else if (val < (parent)->m_data) {
    insert(val, (parent)->m_left);
  } else {
    insert(val, (parent)->m_right);
  }
  return;
}

template <class T>
void BiTree<T>::add_node(const T& val) {
    insert(val, m_root);
}

template <class T>
bool BiTree<T>::find(const T& val, Node<T>* parent) {
  if (parent == nullptr) {
    cout << "data is not find" << endl;
    return false;
  }
  if (val == parent->m_data) {
    cout << "data find!" << endl;
    return true;
  } else if (val <= parent->m_left) {
    find(val, parent->m_left);
  } else {
    find(val, parent->m_right);
  }
}

template <class T>
bool BiTree<T>::is_empty() {
  if (m_root == nullptr)
    return true;
  else
    return false;
}

template <class T>
int BiTree<T>::get_height(Node<T>* parent) {
  if (parent == nullptr) return 1;
  return max(get_height(parent->m_left), get_height(parent->right)) + 1;
}

template <class T>
void BiTree<T>::print_tree(tree_order print_order) {
  switch (print_order) {
    case tree_order::PRE_ORDER:

      /*do something*/
      break;

    case tree_order::IN_ORDER:

      /*do something*/
      break;

    case tree_order::POS_ORDER:

      /*do something*/
      break;

    default:
      break;
  }
}
#endif
