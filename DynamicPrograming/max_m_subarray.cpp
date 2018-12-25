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

// m <= n
int solve(int A[], int n, int m)
{
	int dp[n+1][m+1];
	for (int i = 0; i <= n; ++i)
	{
		dp[i][0] = 0;
	}

	for(int j=1; j<=m; ++j)
	{
		for(int i=1; i<=n; ++i)
		{
			int temp = -1000;
			for(int k=j-1; k<=i-1; ++k)
			{
				temp = max(temp, dp[k][j-1] + sum(A, k+1, i));
			}

			dp[i][j] = temp;
		}
	}

	return dp[n][m];
}

int main()
{
	int A[] = {-2, 1, -3, 4, -1, 2, 1};
	cout << solve(A, 7, 2) << endl;
}