#ifndef UNION_FIND_SET
#define UNION_FIND_SET

/*
 * 并查集类
 */

#include <stdexcept>

using namespace std;

template <size_t N>
class UFS
{
private:
	int* _ufs;
public:
	bool check_range(int index) { return index >= N || index < 0; }

	// 构造函数，不设计拷贝构造函数
	UFS();
	// 析构函数
	~UFS() { if (_ufs) { delete _ufs; } }

	// 查找节点所在集合的根节点，并在查找的过程中优化路径
	inline int get_parent(int index);
	// 将两个节点所在集合合并
	void merge(int x, int y);
};

#endif // !UNION_FIND_SET