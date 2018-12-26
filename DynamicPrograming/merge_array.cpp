#include<iostream>

using namespace std;

int sum(int A[], int s, int e)
{
	int res = 0;
	for(int i=s-1; i<=e-1; ++i)
	{
		res += A[i];
	}
	return res;
}

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

			cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << "    "; 
		}

		cout << endl;
	}

	return dp[1][n];
}

int main()
{
	// int A[] = {1, 2, 3, 4, 5};
	int A[] = {2, 1, 3, 1, 2};
	cout << solve(A, 5) << endl;
}