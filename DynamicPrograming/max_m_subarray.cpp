#include<iostream>

using namespace std;

// 求数组第s - e个元素的最大子数组和，s最小为1
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

// m <= n
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

int main()
{
	int A[] = {-2, 1, -3, 4, -1, 2, 1, -3, 2};
	cout << solve(A, 9, 3) << endl;
}