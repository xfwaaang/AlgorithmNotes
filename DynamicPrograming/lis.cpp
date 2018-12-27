#include<iostream>
#include<vector>

using namespace std;

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
	vector<int> A{5, 3, 4, 6, 2, 7, 8};
	// vector<int> A{5, 3, 4, 4, 8, 6, 7, 4, 8, 8, 9};
	// vector<int> A{5};
	cout << solve(A) << endl;
	cout << solve_1(A) << endl;
}