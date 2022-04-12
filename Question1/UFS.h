#ifndef UNION_FIND_SET
#define UNION_FIND_SET

/*
 * ���鼯��
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

	// ���캯��������ƿ������캯��
	UFS();
	// ��������
	~UFS() { if (_ufs) { delete _ufs; } }

	// ���ҽڵ����ڼ��ϵĸ��ڵ㣬���ڲ��ҵĹ������Ż�·��
	inline int get_parent(int index);
	// �������ڵ����ڼ��Ϻϲ�
	void merge(int x, int y);
};

#endif // !UNION_FIND_SET