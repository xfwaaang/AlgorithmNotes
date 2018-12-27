#include<iostream>
#include<vector>

using namespace std;

// 最长非降子序列
int lis(vector<int>& A)
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

int solve(vector<int>& A)
{
	int n = A.size();
	int res = 2 * n;
	for(int k=1; k<n; ++k)
	{
		// bug
		vector<int> B(A.begin(), A.begin() + k);
		vector<int> C(A.rbegin(), A.rend() - k);

		res = min(res, k - lis(B) + n - k - lis(C));
	}

	return res;
}

int main()
{
	vector<int> A{20, 18, 15, 14, 19, 17, 10, 9, 8, 7, 6, 5, 4, 3};
	vector<int> B{6, 18, 12, 14, 15, 20, 12, 10, 6, 14, 4, 3, 2, 1};
	cout << solve(A) << endl;
	cout << solve(B) << endl;
}