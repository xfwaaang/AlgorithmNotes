/*
问题描述：
有n个物品，它们具有各自的重量和价值，现有给定容量的背包，如何让背包里装入的物品具有最大的价值？
解题思路：
根据动态规划解题步骤找出01背包问题的最优解以及解组成
*/

#include<iostream>

using namespace std;

// 物品数目
int n = 4;
// 物品各自重量与价值
int w[] = {2, 3, 4, 5};
int v[] = {3, 4, 5, 6};

// 背包容量
int capacity = 8;

// 暴力法
int fun1(int n, int capacity, int w[], int v[])
{
	int maxv = 0;
	int currv = 0;
	for(int i=0; i<n; ++i)
	{
		if(capacity > w[i] )
	}
}

int main()
{
	cout << "01背包问题" << endl;
}