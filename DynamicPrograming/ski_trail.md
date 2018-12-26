#### 题目描述
在修建滑雪道时，需要铲掉道上凸起小丘以形成坡道，一条坡道的高度递减或反增  
现在考虑简化的一维滑雪道问题。给定n个整数，分别表示雪道上的高度，请设计一种算法  
降低最少的整数，使之成为只有一条或只有两条坡道的滑雪道  
如下作图所示，降低2个整数（下标4和5），则可形成一条滑雪道  
再如下右图所示，降低2个整数（下标1和9），则可形成两条滑雪道  

#### 解题思路
考虑只要求修建一条滑雪道的情况，可以先求出n个整数的正向序列和反向序列的最长非降子序列的长度  
然后用`n`减去其中的较大者，可以得到修建滑雪道需要降低的最少整数个数  
参考：[最长非降子序列](/DynamicPrograming/lis.md)  
设`A[1:n]`表示`n`个数，`dp(i,j)`表示`A[i:j]`的最优解，从`k`处将序列分为两个部分，则  
```
dp(i,j) = min(i <= k < j){ dp(i,k) + dp(k+1,j) }
```
`k = i || k = j - 1`，表示只修建一条滑雪道  
`k > i && k < j - 1`，表示修建两条滑雪道  
原问题的最优解为
```
dp(1,n) = min(1 <= k < n){ dp(1,k) + dp(k+1,n) }
```
简化求解  
设`dp(n)`表示`A[1:n]`的最优解，`lis(i,j)`表示`A[i:j]`的最长非降子序列的长度，`A[j:i]`表示`A[i:j]`的反向序列，则  
```
dp(n) = min(1 <= k < n){ ( k - lis(A[1:k]) ) + ( n - k - lis(A[n:k+1]) )}
```

#### 代码实现

[code](/DynamicPrograming/ski_trail.cpp)

```
int solve(vector<int>& A)
{
	int n = A.size();
	int res = 2 * n;
	for(int k=1; k<n; ++k)
	{
		vector<int> B(A.begin(), A.begin() + k);
		vector<int> C(A.rbegin(), A.rend() - k);

		res = min(res, k - lis(B) + n - k - lis(C));
	}

	return res;
}
```

```
// 最长非降子序列
int lis(vector<int>& A)
{
	int n = A.size();
	vector<int> dp(n+1, 1);

	for(int i=2; i<=n; ++i)
	{
		for(int j=1; j<=i-1; ++j)
		{
			if(A[i] >= A[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
			else
			{
				dp[i] = max(dp[i], dp[j]);
			}
		}
	}

	return dp[n];
}
```