#include<iostream>
using namespace std;

// 计算x的二进制表示中1和0的个数

int binary1num(int x)
{
	int num = 0;

	while(x)
	{
		x = x & (x-1);
		num++;
	}

	return num;
}

int binary0num(int x)
{
	int num = 0;

	while(x+1)
	{
		x = x | (x+1);
		num++;
	}

	return num;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 100; ++i)
	{
		cout << i << "二进制表示中1的个数：" << binary1num(i) << endl;
		cout << i << "二进制表示中0的个数：" << binary0num(i) << endl;
	}
	return 0;
}

