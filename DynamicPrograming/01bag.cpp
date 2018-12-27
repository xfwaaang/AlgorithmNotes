/*
问题描述：
##### 问题一  
有n个物品，它们具有各自的重量wi和价值vi，现有给定容量的背包，如何让背包里装入的物品具有最大的价值？  
  
##### 问题二  
给定n个物品种类，（例如：水果类、饮料类、工具类），每个种类包含m个物品（例如水果类中包含苹果、桔子、樱桃）  
第i种类第j物品有大小s(i,j)，价值v(i,j)。背包容量为C。请设计一动态规划算法，寻找一组物品装入背包，使装入  
背包内的物品价值最大（不要求完全占满），且要求每个种类最多被转入一个物品  
*/

#include<iostream>

using namespace std;

// 问题一

// 物品数目
int n = 4;
// 物品各自重量与价值
int w[] = {5, 4, 3, 2};
int v[] = {6, 5, 4, 3};

// 背包容量
int c = 8;

int solve(int n, int c, int w[], int v[])
{
	int dp[n+1][c+1];
	// 背包容量为0
	for(int i=0; i<=n; ++i)
	{
		dp[i][0] = 0;
	}
	// 可选物品数为0
	for(int j=0; j<=c; ++j)
	{
		dp[0][j] = 0;
	}

	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=c; ++j)
		{
			if(j < w[i-1])
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
			}
		}
	}

	return dp[n][c];
}

// 动态规划
// int fun(int n, int c, int w[], int v[])
// {
// 	int a[n+1][c+1] = {};
// 	for(int i=1; i<=c; ++i)
// 	{
// 		for(int j=1; j<=n; ++j)
// 		{
// 			if(i < w[j-1])
// 				a[j][i] = a[j-1][i];
// 			else
// 				a[j][i] = max(a[j-1][i], a[j-1][i-w[j-1]] + v[j-1]);
// 		}
// 	}
// 	return a[n][c];
// }

// 问题二

int solve_2(int n, int c, int m, vector<vector<int>>& s, vector<vector<int>>& v)
{
	int dp[n+1][c+1];
	// 背包容量为0
	for(int i=0; i<=n; ++i)
	{
		dp[i][0] = 0;
	}
	// 可选物品种类数为0
	for(int j=0; j<=c; ++j)
	{
		dp[0][j] = 0;
	}

	// 当前背包容量j是否大于第i类的某个物品大小
	bool flag = false;

	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=c; ++j)
		{
			flag = false;
			for(int k=1; k<=m; ++k)
			{
				if(j >= s[i-1][k-1])
				{
					flag = true;
					dp[i][j] = max(dp[i-1][j], dp[i-1][j-s[i-1][k-1]] + v[i-1][k-1]);
				}
			}

			// 当前背包容量j小于第i种类的任一物品大小，不能放入
			if(!flag)
			{
				dp[i][j] = dp[i-1][j];
			}
		}

	}

	return dp[n][c];
}

int main()
{
	cout << "01背包问题" << endl;
	// 问题一
	// cout << fun(n, c, w, v) << endl;
	cout << solve(n, c, w, v) << endl;

	// 问题二
	
}