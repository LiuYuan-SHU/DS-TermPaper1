#include "UFS.h"
#include <stdexcept>

using namespace std;

template <size_t N>
UFS<N>::UFS() : _ufs(nullptr)
{
	this->_ufs = static_cast<int*>(malloc(sizeof(int) * N));
	for (int i = 0; i < N; i++)
	{
		_ufs[i] = i;
	}
}

template <size_t N>
inline int UFS<N>::get_parent(int index)
{
	if (!check_range(index))
	{
		throw out_of_range;
	}

	// 如果自己的下标就是自身，说明自己就是根节点
	if (_ufs[index] == index) { return index; }
	// 否则递归调用，直到找到根节点
	else { return _ufs[index] = get_parent(_ufs[index]); }
}

template <size_t N>
void UFS<N>::merge(int x, int y)
{
	int parent_x = get_parent(x);
	int parent_y = get_parent(y);

	if (parent_x == parent_y) { return; }
	else { _ufs[y] = x; }
}
