#include "DataInit.h"
#include "FileOpe.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

#define TEST

using namespace std;

void test_DataInit()
{
	DataInit<1000> test;
	test.showData();
}

void test_FileOpe_in()
{
	FileIn fi;
	cout << "Finished, result: " << fi.runtime() - 1 << endl;
	FileOut fout(fi.runtime() - 1);
}

int main()
{
	test_DataInit();
	test_FileOpe_in();
}