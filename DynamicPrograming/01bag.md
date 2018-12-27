#### 问题描述
##### 问题一  
有`n`个物品，它们具有各自的重量`wi`和价值`vi`，现有给定容量的背包，如何让背包里装入的物品具有最大的价值？  
  
##### 问题二  
给定`n`个物品种类，（例如：水果类、饮料类、工具类），每个种类包含`m`个物品（例如水果类中包含苹果、桔子、樱桃）  
第`i`种类第j物品有大小`s(i,j)`，价值`v(i,j)`。背包容量为`c`。请设计一动态规划算法，寻找一组物品装入背包，使装入  
背包内的物品价值最大（不要求完全占满），且要求每个种类最多被转入一个物品  

#### 解题思路
##### 问题一  
设`dp(i,j)`表示可选物品为`1 - i`，背包容量为`j`时的最优解  
考虑物品`i`
若`j < wi`，物品`i`无法放入背包，只能从物品`1 - i-1`中挑选，即`dp(i,j) = dp(i-1,j)`  
若`j >= wi`，物品`i`可以选择不放入和放入背包，选出其中较好的结果，即`dp(i,j) = max{dp(i-1,j), dp(i-1,j-wi) + vi}`
```
dp(i,j) = dp(i-1,j)					j < wi
dp(i,j) = max{ dp(i-1,j), dp(i-1,j-wi) + vi }		j >= wi
```

##### 问题二  
设`dp(n,c)`表示可选物品种类为`1 - n`，背包容量为`c`时的最优解  
考虑第`n`类物品，若c小于第n类物品中任一物品，则不能将第n类的任何物品放入  
若c大于等于第n类物品中某一物品，可以考虑将其放入或者不放入  
```

dp(n,c) = dp(n-1,c)						c < s(n,1), s(n,2),..., s(n,m)
dp(n,c) = max{ dp(n-1,c), dp(n-1,c-s(n,j)) + v(n,j) }		c > s(n,j) && 1 <= j <= m	
```

#### 代码实现

[code](/DynamicPrograming/01bag.cpp)

##### 问题一
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

##### 问题二

```
int solve(int n, int c, int m, vector<vector<int>>& s, vector<vector<int>>& v)
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
```