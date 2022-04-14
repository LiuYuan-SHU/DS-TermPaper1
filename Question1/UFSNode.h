#include "UFS.h"
#ifndef NODE
#define NODE

struct Node
{
	int _num;
	Node* _next;

	Node(int n = 0) : _num(n), _next(nullptr) {}
	~Node();

	inline void set_Num(int num) { this->_num = num; }
	inline void set_Next(Node* next) { this->_next = next; }
	inline int& get_Num() { return this->_num; }
	inline Node* get_Next() { return this->_next; }

	inline void add_next(int n);
};

Node::~Node()
{
	Node *current,*temp;
	current = this->_next;
	while (temp = current)
	{
		current = current->_next;
		delete temp;
	}
}

inline void Node::add_next(int n)
{
	// 此处之所以要新建一个node来存放数据，是为了避免析构函数的时候析构不存在的空间
	Node* newNode = new Node(n);

	Node* ite = this;
	while (ite->_next) { ite = ite->_next; }

	ite->set_Next(newNode);
}

#endif