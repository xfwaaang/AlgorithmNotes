#### 题目描述
给定n个数，每次只能合并相邻的两个数，合并的代价是两个数之和，两个数合并得到的数为两个数之和，求合并所有数的最小代价

#### 解题思路
设A[1:n]表示给定的n个数，dp(i,j)表示合并A[i:j]的最优解，sum(i,j)表示A[i:j]的所有元素之和  
1. i = j，只有一个数，不用合并
2. i > j，dp(i,j) = 0
3. i+1 = j，	即合并相邻两个数
```
dp(i,j) = 0		i >= j
dp(i,j) = min(i <= k < j){ dp(i,k) + dp(k+1,j) + sum(i,j) }		i < j - 1
dp(i,j) = sum(i,j)		i+1 = j
```

#### 代码实现

[code](/DynamicPrograming/merge_array.cpp)

```
int solve(int A[], int n)
{
	int dp[n+1][n+1];
	// i >= j, dp = 0
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=i; ++j)
		{
			dp[i][j] = 0;
		}
	}
	// j = i + 1, 即合并相邻两个数，dp = ai + aj
	for(int i=1; i<n; ++i)
	{
		dp[i][i+1] = sum(A, i, i+1);
	}

	for(int x=1; x<=n-1; ++x)
	{
		for(int i=1; i<=n-x; ++i)
		{
			int j = i + x;
			dp[i][j] = 100000;
			for(int k=i; k<=j-1; ++k)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum(A, i, j));
			}

		}

	}

	return dp[1][n];
}
```
```
int sum(int A[], int s, int e)
{
	int res = 0;
	for(int i=s-1; i<=e-1; ++i)
	{
		res += A[i];
	}
	return res;
}
```