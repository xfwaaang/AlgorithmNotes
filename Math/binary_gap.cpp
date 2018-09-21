/*
题目描述：
给定正整数N，找到并返回N的二进制表示中两个连续1之间的最长距离。 
如果没有连续两个1，则返回0。
Input: 5
Output: 2
Explanation: 
5 in binary is 0b101.
Input: 8
Output: 0
Explanation: 
8 in binary is 0b1000.
*/

#include<iostream>
#include<vector>
#include"../util.h"

using namespace std;

int binaryGap(int N)
{
	vector<int> a;
	int k = 0;
	while(N)
	{
		int tmp = N % 2;
		if(tmp)	k++;
		a.push_back(tmp);
		N /= 2;
	}

	if(k == 1)	return 0;

	int i = 0, j = 0;
	int gap = 0;
	int n = a.size();

	while(i < n && j < n)
	{
		while(i < n && a[i] == 0)	++i;
		while(i < n && a[i] == 1)	++i;
		j = i;

		while(j < n && a[j] == 0)	++j;

		gap = max(gap, j - i + 1);
		i = j;
	}

	return gap;
}

int binaryGap_2(int N)
{
	int maxd = 0;
	int d = 0;
	bool count = false;

	while(N)
	{
		if(N & 1)
		{
			count = true;
			maxd = max(maxd, d);
			d = 0;
		}

		if(count)
			d++;

		N >>= 1;
	}

	return maxd;
}

int main()
{
	int N = 6;
	cout << binaryGap(N) << endl;
	cout << binaryGap_2(N) << endl;
}