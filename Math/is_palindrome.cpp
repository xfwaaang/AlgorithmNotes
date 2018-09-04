/*
题目描述：
判断一个整数是否为回文数
*/
#include<iostream>
#include"../util.h"

using namespace std;

bool isPalindrome(int x)
{
	if(x < 0)
		return false;

	int reverse = 0;
	int tmp = x;
	while(tmp)
	{
		reverse = reverse * 10 + tmp % 10;
		tmp /= 10;
	}
	return x == reverse;
}

int main()
{
	cout << "判断回文数" << endl;
	vector<int> a = genRandomArray(10000, 0, 10000);
	for(int i=0; i<10000; ++i)
	{
		if (isPalindrome(a[i]))
		{
			cout << a[i] << " ";
		}
	}
}