#ifndef UNION_FIND
#define UNION_FIND

/*
 * 并查集类
 */

#include <vector>

using namespace std;

template <size_t N>
class UnionFind
{
private:
	vector<int> _ufs;
public:
	// 构造函数，不需要设计拷贝构造和析构函数
	UnionFind() : _ufs(N, -1) {}



};

#endif // !UNION_FIND