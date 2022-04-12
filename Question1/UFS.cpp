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

	// ����Լ����±��������˵���Լ����Ǹ��ڵ�
	if (_ufs[index] == index) { return index; }
	// ����ݹ���ã�ֱ���ҵ����ڵ�
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
