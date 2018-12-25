#### 问题描述
有n个物品，它们具有各自的重量wi和价值vi，现有给定容量的背包，如何让背包里装入的物品具有最大的价值？

#### 解题思路
设`dp(i,j)`表示可选物品为`1 - i`，背包容量为j时的最优解  
考虑物品`i`
若`j < wi`，物品`i`无法放入背包，只能从物品`1 - i-1`中挑选，即`dp(i,j) = dp(i-1,j)`  
若`j >= wi`，物品`i`可以选择不放入和放入背包，选出其中较好的结果，即`dp(i,j) = max{dp(i-1,j), dp(i-1,j-wi) + vi}`
```
dp(i,j) = dp(i-1,j)		j < wi
dp(i,j) = max{dp(i-1,j), dp(i-1,j-wi) + vi}		j >= wi
```

#### 代码实现

[code](/DynamicPrograming/01bag.cpp)

```
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
```