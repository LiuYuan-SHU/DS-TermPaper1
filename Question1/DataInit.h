#ifndef DATA_INIT
#define DATA_INIT

#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

#define FILE_NAME	"virus.in"
#define TEST
// ��TESTģʽ�£����ɵ�ͬ����������10
#ifdef TEST

// #define N		10
#define RESULT	10		// ���ɵ�ͬ������

#endif

template <size_t N = 100>
class DataInit
{
private:
#ifndef RESULT
	int RESULT;			// ���ɵ�ͬ������
#endif // RESULT
	int SPLITED_LENGTH = RESULT - 1;	// ��¼�ָ������
	int* _data;							// ��¼����
	int* _split;
public:
	DataInit();
	~DataInit()	{ delete _data;	}

	// ��������
	void shuffle();
	// ��_data�ֳ�һ��һ��С���飬ÿһ���������һ��ͬ��
	// ���ص�����ĳ���ΪRESULT - 1��ͬʱÿ��Ԫ�ؼ�¼��ÿ��������һ��Ԫ�ص��±�
	int* split();
	// �����ɵ���������ѡ���ݣ�д�뵽�ļ���
	void write();

	void showData();
};

template<size_t N>
inline DataInit<N>::DataInit()
{
	// ���û����TESTģʽ�£���Ҫ�����������ͬ�������
#ifndef RESULT
	while (RESULT = rand() % 100, RESULT > 0 && RESULT < N);
#endif
	
	// ��ʼ������
	this->_data = new int[N];
	for (int i = 0; i < N; i++) { this->_data[i] = i + 1; }

	// �����������
	shuffle();

	// д�����
	write();
}

template<size_t N>
void DataInit<N>::shuffle()
{
	srand(time(nullptr));

	for (int i = 0, temp; i < N; i++)
	{
		int indexToSwap;
		while (indexToSwap = static_cast<double>((rand() % N) * 0.01) * (i + 1), indexToSwap > RESULT);

		temp = this->_data[indexToSwap];
		this->_data[indexToSwap] = this->_data[i];
		this->_data[i] = temp;
	}
}

template<size_t N>
int* DataInit<N>::split()
{
	int* splited = new int[SPLITED_LENGTH];

	bool exist = false;
	for (int i = 0, temp; i < SPLITED_LENGTH; i++, exist = false)
	{
		temp = rand() % N;
		for (int j = 0; j < i; j++)
		{
			if (temp == splited[j]) { exist = true; break; }
		}
		if (!exist) { splited[i] = temp; }
		else { i--; }
	}

	int temp;
	for (int i = 0; i < SPLITED_LENGTH; i++)
	{
		for (int j = i; j <= SPLITED_LENGTH - 1; j++)
		{
			if (splited[i] > splited[j])
			{
				temp = splited[i];
				splited[i] = splited[j];
				splited[j] = temp;
			}
		}
	}

	return this->_split =  splited;
}

template<size_t N>
void DataInit<N>::write()
{
	// int sets = rand() % static_cast<int>(pow(2, N));
	int sets = 100;
	int* splited_data = split();

	// ��ӡ��������������
	ofstream fout(FILE_NAME, ofstream::out);
	fout << N << endl;
	fout << sets << endl;

	int flag = 0;	// flag��0����S��1����H
	for (int i = 0; i < sets; i++, flag = rand() % 2)
	{
		// �����H��Ҳ���������
		if (flag)
		{
			/*static int offset = 0;
			int value1, value2;
			int index_mid;

			try
			{
				if (SPLITED_LENGTH == 1)
				{
					value1 = this->_data[rand() % splited_data[0]];
					value2 = this->_data[rand() % (RESULT - splited_data[0]) + splited_data[0]];
				}
				else if (SPLITED_LENGTH == 2)
				{
					value1 = this->_data[rand() % splited_data[0]];
					value2 = this->_data[rand() % (splited_data[1] - splited_data[0]) + splited_data[0]];
				}
				else
				{
					if (offset >= SPLITED_LENGTH - 2) { offset = 0; }
					value1 = value2 = 0;
					while (value1 == value2)
					{
						value1 = this->_data[rand() % (splited_data[offset] - (offset == 0 ? 0 : splited_data[offset - 1])) + (offset == 0 ? 0 : splited_data[offset - 1])];
						value2 = this->_data[rand() % (splited_data[offset + 1] - (offset == 0 ? 0 : splited_data[offset])) + (offset == 0 ? 0 : splited_data[offset])];
					}
				}
			}
			catch (exception e)
			{
				continue;
			}
			fout << "H " << value1 << "\t" << value2 << endl;*/
		}
		else
		{
			int index = rand() % SPLITED_LENGTH;
			int left_index = index == 0 ? splited_data[0] : splited_data[index - 1];
			int right_index = index == 0 ? splited_data[1] : splited_data[index];
			int minus_index = right_index - left_index;
			int value1, value2;
			value1 = this->_data[(rand() % minus_index) + left_index];
			value2 = this->_data[(rand() % minus_index) + left_index];
			fout << "S " << value1 << "\t" << value2 << endl;
		}
	}

	fout.close();
}

template<size_t N>
void DataInit<N>::showData()
{
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		cout << _data[i] << "\t";
		if (_data[i] == _split[j])
		{
			cout << endl;
			j++;
		}
	}
}

#endif
