#include<iostream>
#include<cmath>
using namespace std;

/*
题目描述：
翻转一个整数
ex：x = 123，return	321
ex：x = -918，return -819
*/

int reverse(int x)
{
	bool flag = 0;
	if (x < 0)
	{
		x = -x;
		flag = 1;
	}

	int k = 1;
	while(x / k >= 10)
		k *= 10;

	int res = 0;
	while(x)
	{
		res += k * (x % 10);
		x /= 10;
		k /= 10;
	}

	if (flag == 1)
	{
		res = -res;
	}
	return res;
}

int reverse_2(int x)
{
	int temp = abs(x);
	int res = 0;

	while(temp)
	{
		res = res * 10 + temp % 10;
		temp /= 10;
	}

	return x > 0 ? res : -res;
}

int main()
{
	for (int i = -200; i <= 200; ++i)
	{
		cout << i << " -> " << reverse(i) << " -> " << reverse_2(i) << endl; 
	}
}