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
int c = 8;

// 动态规划
int fun(int n, int c, int w[], int v[])
{
	int a[n+1][c+1] = {};
	for(int i=1; i<=c; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if(i < w[j-1])
				a[j][i] = a[j-1][i];
			else
				a[j][i] = max(a[j-1][i], a[j-1][i-w[j-1]] + v[j-1]);
		}
	}
	return a[n][c];
}

int main()
{
	cout << "01背包问题" << endl;
	cout << fun(n, c, w, v) << endl;
}