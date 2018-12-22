#### 题目描述
给定一个含有n个数的序列A，求其最长非降子序列的长度  
注意：子序列不要求连续  
例如：序列 `5, 3, 4, 6, 2, 7, 8` 的最长非降子序列为`3, 4, 6, 7, 8`，长度为`5`  

#### 解题思路
用dp(i)表示前i个数的最长非降子序列的长度   
`dp(i) = max{dp(j) + 1}`      `j < i, A[j] <= A[i]`  
`dp(i) = max{dp(j)}`          `j < i, A[j] > A[i]`  
例如：序列`5, 3, 4, 6, 2, 7, 8`  
`dp(1) = 1`  
`dp(2) = dp(1) = 1`       `A[2] < A[1]`  
`dp(3) = dp(2) + 1 = 2`   `A[3] > A[2]`  
`dp(4) = dp(3) + 1 = 3`   `A[4] > A[3]`  
`dp(5) = dp(4) = 3`       `A[5] < A[4]`  
`dp(6) = dp(5) + 1 = 4`   `A[6] > A[4]`  
`dp(7) = dp(6) + 1 = 5`   `A[7] > A[6]`

#### 代码实现
[code](/DynamicPrograming/lis.cpp)  
```
int solve(vector<int>& A)
{
	int n = A.size();
	vector<int> help(n + 1, 1);

	for(int i=1; i<n; ++i)
	{
		for(int j=0; j<i; ++j)
		{
			if(A[j] <= A[i])
			{
				help[i+1] = help[j+1] + 1;
			}else
			{
				help[i+1] = help[j+1];
			}
		}
	}

	return help[n];
}
```