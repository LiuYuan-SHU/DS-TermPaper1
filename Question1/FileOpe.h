#ifndef FILE_OPE
#define FILE_OPE

#include <iostream>
#include <fstream>
#include <string>

#define FILE_NAME_IN	"virus.in"
#define FILE_NAME_OUT	"virus.out"

using namespace std;

class FileIn
{
private:
	ifstream _fin;
	int _ArraySize;
	int _ReadTime;
public:
	FileIn();
	~FileIn() { if (_fin.is_open()) { _fin.close(); } }

	const int& get_arraySize() { return this->_ArraySize; }
	const int& get_ReadTime() { return this->_ReadTime; }

	// 处理所有数据，最终返回组数
	int runtime();
};

class FileOut
{
private:
	ofstream _fout;
public:
	FileOut(int output)
	{
		_fout.open(FILE_NAME_OUT,std::ofstream::app);
		_fout << output << endl;
	}
	~FileOut() { if (_fout.is_open()) { _fout.close(); } }
};

#endif