#ifndef UNION_FIND
#define UNION_FIND

/*
 * ���鼯��
 */

#include <vector>

using namespace std;

template <size_t N>
class UnionFind
{
private:
	vector<int> _ufs;
public:
	// ���캯��������Ҫ��ƿ����������������
	UnionFind() : _ufs(N, -1) {}



};

#endif // !UNION_FIND