#### 题目描述
给定一个含有n个数的序列A，求其最长非降子序列的长度  
注意：子序列不要求连续  
例如：序列 `5, 3, 4, 6, 2, 7, 8` 的最长非降子序列为`3, 4, 6, 7, 8`，长度为`5`  

#### 解题思路
设A[1:n]表示n个数，用dp(i)表示以第i个数为结尾的的最长非降子序列的长度  
``` 
			1		                 ，i = 1
dp(i) = max(1 <= j < i && A[j] <= A[i]){ dp(j)} + 1      , i > 1
        若没有满足条件的j，则dp[i] = 1;
```
  
#### 代码实现
[code](/DynamicPrograming/lis.cpp)  
```cpp
int solve(vector<int>& A)
{
	int n = A.size();
	int max_dp = 1;
	vector<int> dp(n+1, 1);

	for(int i=2; i<=n; ++i)
	{
		int tmp = -1;
		for(int j=1; j<=i-1; ++j)
		{
			if(A[i-1] >= A[j-1])
			{
				tmp = max(tmp, dp[j]);
			}
		}
		
		dp[i] = (tmp == -1 ? 1 : tmp + 1);
		max_dp = max(max_dp, dp[i]);
	}

	return max_dp;
}
```
