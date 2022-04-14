#ifndef UNION_FIND_SET
#define UNION_FIND_SET

/*
 * 并查集类
 */

#include "UFSNode.h"
#include <iostream>
#include <stdexcept>
#include <set>

using namespace std;

class UFS
{
private:
	int N;
	Node** _ufs;
public:
	// 构造函数，不设计拷贝构造函数
	UFS(int n);
	// 析构函数
	~UFS() { if (_ufs) { delete _ufs; } }

	bool check_range(int index) = delete;

	// 查找节点所在集合的根节点，并在查找的过程中优化路径
	inline int get_parent(int index);
	// 将两个节点所在集合合并
	void merge(int x, int y);
	// 将相克节点进行存储
	void counter(int x, int y);
	// 将相克节点放入同一个类中
	void merge_counter();
	// 统计有多少个类
	int countNodes();
	// 打印整个_ufs数组
	void showUFS();
};


inline UFS::UFS(int n) : _ufs(nullptr), N(n)
{
	this->_ufs = new Node*[N];
	for (int i = 0; i < N; i++)
	{
		this->_ufs[i] = new Node(i);
	}
}


inline int UFS::get_parent(int index)
{
	// 如果自己的下标就是自身，说明自己就是根节点
	// clog << "index: " << index << endl;
	// clog << "_ufs[index]: " << _ufs[index]->get_Num() << endl;
	if (_ufs[index]->get_Num() == index) { return index; }
	// 否则递归调用，直到找到根节点
	else { return _ufs[index]->get_Num() = get_parent(_ufs[index]->get_Num()); }
}

void UFS::merge(int x, int y)
{
	int parent_x = get_parent(x);
	int parent_y = get_parent(y);

	if (parent_x == parent_y) { return; }
	else { _ufs[parent_x]->set_Num(parent_y); }
}

inline void UFS::counter(int x, int y)
{
	// cout << __func__ << endl;
	// this->showUFS();
	int parent_x = get_parent(x);
	int parent_y = get_parent(y);

	if (parent_x == parent_y) { return; }
	else { _ufs[x]->add_next(_ufs[y]->get_Num()); }
}

inline void UFS::merge_counter()
{
	Node* nodes, * temp;
	for (int i = 0; i < N; i++)
	{
		nodes = this->_ufs[i]->get_Next();
		while (nodes && nodes->get_Next())
		{
			this->merge(nodes->get_Num(), nodes->get_Next()->get_Num());
			nodes = nodes->get_Next();
		}
	}
}

int UFS::countNodes()
{
	for (int i = 0; i < N; i++)
	{
		this->get_parent(this->_ufs[i]->get_Num());
	}

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (_ufs[i]->get_Num() == i)
		{
			count++;
		}
	}

	return count;
}

inline void UFS::showUFS()
{
	Node* temp;
	for (int i = 1; i < N; i++)
	{
		cout << i << ":\t" << this->_ufs[i]->get_Num() << " -> ";
		temp = this->_ufs[i]->get_Next();
		do
		{
			if (temp) { cout << temp->get_Num() << " -> "; temp = temp->get_Next(); }
			if (!temp) { cout << "NULL\n"; }
		} while (temp);
	}
}


#endif // !UNION_FIND_SET