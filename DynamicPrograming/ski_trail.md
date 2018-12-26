#### 题目描述
在修建滑雪道时，需要铲掉道上凸起小丘以形成坡道，一条坡道的高度递减或反增  
现在考虑简化的一维滑雪道问题。给定n个整数，使之成为只有一条或只有两条坡道的滑雪道  
如下作图所示，降低2个整数（下标4和5），则可形成一条滑雪道  
再如下右图所示，降低2个整数（下标1和9），则可形成两条滑雪道  

#### 解题思路


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