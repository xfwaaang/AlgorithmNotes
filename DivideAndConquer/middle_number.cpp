/*
题目描述：
给定两个有序数组，求合并后的中位数
要求时间复杂度：O(logn)
*/

#include<iostream>
#include"../util.h"

using namespace std;


// 两个数组长度相等

// 递归
int fun(int a[], int b[], int n)
{
	if(n == 1)	return (a[0] + b[0]) / 2.0;

	int m = n / 2;

	if(a[m] < b[m])	return fun(a+m, )
}

int main()
{
	cout << "求两个有序数组的中位数" << endl;
	return 0;
}