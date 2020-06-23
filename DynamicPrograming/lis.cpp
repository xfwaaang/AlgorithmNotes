#include<iostream>
#include<vector>
#include"../util.h"

using namespace std;

int solve_2(vector<int>& A)
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

//error
int solve_1(vector<int>& A)
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

//erro
int solve(vector<int>& A)
{
	int n = A.size();
	vector<int> dp(n+1, 1);

	for(int i=2; i<=n; ++i)
	{
		for(int j=1; j<=i-1; ++j)
		{
			if(A[i-1] >= A[j-1])
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

int main()
{
	// vector<int> A{5, 3, 4, 6, 2, 7, 8};
	// vector<int> A{5, 3, 4, 4, 8, 6, 7, 4, 8, 8, 9};
	// vector<int> A{5};
	vector<int> A = genRandomArray();
	// vector<int> A{1, 3, 5, 2, 4};
	printArray(A);
	cout << solve(A) << endl; //错误
	cout << solve_1(A) << endl; //错误
	cout << solve_2(A) << endl; //正确
}
