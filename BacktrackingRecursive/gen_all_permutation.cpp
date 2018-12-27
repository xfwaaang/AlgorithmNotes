/*
题目描述：
产生各种可能的排列
给定n个自然数{0,1,2...，n}，产生所有可能的排列（permutation）
解题思路：
以4个自然数为例{0,1,2,3}
1. 0开头，其后是{1,2,3}的各种排列
2. 1开头，其后是{0,2,3}的各种排列
依次类推，以2开头、以3开头
此问题的实质是求解比原始问题少一个数的排列，这是一个同类子问题，可以用递归算法求解。
*/

#include<iostream>
#include"../util.h"

using namespace std;

/*
输出所有可能的排列
k：起始位置
n：数组长度
*/
template<class T>
int permutation(T a[], int k, int n)
{
	static int count = 0;

	if(k == n-1)
	{
		// 输出一种排列
		printArray(a, n);
		count++;
	}
	else
	{
		// 产生a[k]-a[n]之间的各种排列
		for(int i=k; i<n; ++i)
		{
			swap(a, i, k);
			// 产生a[k+1]-a[n]之间的各种排列
			permutation(a, k+1, n);
			swap(a, i, k);
		}
	}

	return count;
}

/*
输出数组的所有可能排列
*/
int perm(int a[], int n)
{
	return permutation(a, 0, n);
}

int main()
{
	int a[] = {0, 1, 2};
	cout << perm(a, 3) << endl;
}



