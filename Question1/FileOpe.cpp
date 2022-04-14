#include "FileOpe.h"
#include "UFS.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

FileIn::FileIn()
{
	_fin.open(FILE_NAME_IN);
	if (_fin.fail()) { cout << "Open file fail" << endl; return; }

	// 获取数据大小和读取次数
	_fin >> _ArraySize >> _ReadTime;	

	clog << "Array Size:\t" << _ArraySize << endl;
	clog << "Read Time:\t" << _ReadTime << endl;
}

int FileIn::runtime()
{
	char flag;
	int value1, value2;
	UFS ufs(this->_ArraySize + 1);
	// ufs.showUFS();
	// cout << "======================================" << endl;
	while (_fin >> flag >> value1 >> value2, !_fin.fail())
	{
		if (flag == 'S')
		{
			// cout << "s: " << endl;
			// cout << value1 << "\t" << value2 << endl;
			ufs.merge(value1, value2);
		}
		else
		{
			// cout << "h: " << endl;
			// cout << value1 << "\t" << value2 << endl;
			ufs.counter(value1, value2);
		}
		//ufs.showUFS();
		// cout << "======================================" << endl;
	}
	
	ufs.merge_counter();

	ufs.showUFS();

	int count = ufs.countNodes();

	return count;
}
