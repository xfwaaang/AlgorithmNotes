/*
题目描述：
给定一个整数，将其转换为罗马数字。
输入保证在1到3999的范围内。
*/

#include<iostream>
#include<string>
#include"util.h"

using namespace std;

// 1000, 900, 500, 400, 100,90, 50, 40, 10, 9, 5, 4, 1
// "M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"

string int2roman(int num)
{
	string res = "";
	int value[] = {1000, 900, 500, 400, 100,90, 50, 40, 10, 9, 5, 4, 1};
	string flag[] = {"M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int n = length(value);
	for (int i = 0; i < n; ++i)
	{
		if(num < value[i])
			continue;
		while(num >= value[i])
		{
			num -= value[i];
			res += flag[i];
		}
	}
	return res;
}

int main()
{
	for (int i = 1; i < 4000; ++i)
	{
		cout << int2roman(i) << "  ";
	}
}