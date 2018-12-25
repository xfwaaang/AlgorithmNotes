#include<iostream>
#include<string>

using namespace std;

int solve(string s, string t)
{
	int m = s.size();
	int n = t.size();

	int dp[m+1][n+1];
	for(int i=0; i<=m; ++i)
	{
		dp[i][0] = 0;
	}
	for(int j=0; j<=n; ++j)
	{
		dp[0][j] = 0;
	}

	for(int i=1; i<=m; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if(s[i-1] == t[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
			{
				if(i == j)
				{
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else if(i < j)
				{
					dp[i][j] = dp[i][j-1] + 1;
				}
				else
				{
					dp[i][j] = dp[i-1][j] + 1;
				}
			}
		}
	}

	return dp[m][n];
}

int main()
{
	string s = "abcd";
	string t = "abcedf";

	cout << solve(s, t) << endl;
}