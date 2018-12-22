#### 问题描述
有n个物品，它们具有各自的重量和价值，现有给定容量的背包，如何让背包里装入的物品具有最大的价值？

#### 解题思路
根据动态规划解题步骤找出01背包问题的最优解以及解组成

#### 代码实现

[code](/DynamicPrograming/01bag.cpp)

```
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
```