#ifndef _BI_TREE_H_
#define _BI_TREE_H_

#include <iostream>
using namespace std;

template <class T>
class Node{
public:
	T m_data;
	Node<T>* m_left, m_right;
	Node<T>(const T& d):m_data(d), m_left(nullptr), m_right(nullptr){} 
	/*Note: = delete means that the compiler will not 
	  generate those constructors for you. 
	  this is only allowed on copy constructor and assignment operator.
	 */

	Node<T>& operator=(const Node<T>&) = delete;
}

template <class T>
class BiTree{
public:
	BiTree();
	~BiTree(){ delete [] root };
	void insert(const T&);
	void find(T&);
	bool is_empty();
	int ger_height();

private:
	T* root;
}


#endif