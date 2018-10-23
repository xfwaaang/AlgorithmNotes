/*
题目描述：
给定两个序列X和Y，求它们的最长公共子序列的长度(longest common subsequence)
解题思路：
设X[m]=(x1,x2,...,xm)和Y[n]=(y1,y2,...,yn)，Z=(z1,z2,...,zk)是X和Y的最长公共子序列，则

1. 若xm = yn，则zk=xm=yn，且Z[k-1]是X[m-1]和Y[n-1]的最长公共子序列
2. 若xm！= yn且zk！= xm，则Z是X[m-1]和Y的最长公共子序列
3. 若xm！= yn且zk！= yn，则Z是X和Y[n-1]的最长公共子序列

我们需要一个二维数组来保存最长公共子序列的长度，设c[i][j]保存X[i]=(x1,x2,...,xi)和Y[j]=(y1,y2,...,yj)的最长子序列的长度

	       0                           i=0 or j=0      
c[i][j] ={ c[i-1][j-1] + 1             i,j>0, xi = yj
           max(c[i-1][j], c[i][j-1])   i,j>0, xi != yj

*/

#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int LCSLength(string x, string y)
{
	int m = x.size();
	int n = y.size();
	int c[m+1][n+1];

	for(int i=0; i<=m; i++)	c[i][0] = 0;
	for(int i=0; i<=n; i++) c[0][i] = 0;

	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(x[i] == y[j])
			{
				c[i][j] = c[i-1][j-1] + 1;
			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j] = c[i-1][j];
			}
			else
			{
				c[i][j] = c[i][j-1];
			}

		}

	}

	return c[m][n];
}

int main()
{
	string x, y;

	while(cin >> x >> y)
	{
		cout << LCSLength(x, y) << endl;
	}

}