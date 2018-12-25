#### 题目描述
给定n个数，选择m个不相交的子段，使得所有子段和最大  
子段是连续的

#### 解题思路
当`m = 1`时，即求`n`个数的最大子段和，参考：[具有最大和的子数组](/Array/max_subarray.md)  
设`dp(i,j)`为从前`i`个数中选择`j`个子段的最优解，即`j`个子段和最大  
设`maxSubArray(A, s, e)`求数组`A`第`s - e`个元素的最大子数组和，`s`最小为1  
设`j-1 <= k < i`，先从前`k`个数中选择`j-1`个子段，再从第`k - i`数中选择一个子段，则
```
dp(i,j) = max(j-1 <= k < i){dp(k,j-1) + maxSubArray(A, k+1, i)}
```

#### 代码实现

[code](/DynamicPrograming/max_m_subarray.cpp)

```
int solve(int A[], int n, int m)
{
	int dp[n+1][m+1];
	for (int i = 0; i <= n; ++i)
	{
		dp[i][0] = 0;
		dp[i][1] = maxSubArray(A, 1, i);
	}

	for(int j=2; j<=m; ++j)
	{
		for(int i=j; i<=n; ++i)
		{
			int temp = -1000;
			for(int k=j-1; k<=i-1; ++k)
			{
				temp = max(temp, dp[k][j-1] + maxSubArray(A, k+1, i));
			}

			dp[i][j] = temp;
		}
	}

	return dp[n][m];
}
```

```
int maxSubArray(int A[], int s, int e)
{
	if(s > e)
	{
		return 0;
	}

	int sum = A[s-1];
	int maxSum = sum;

	for(int i=s; i<=e-1; ++i)
	{
		if(sum < 0)
			sum = 0;
		sum += A[i];
		maxSum = max(sum, maxSum);
	}

	return maxSum;
}
```