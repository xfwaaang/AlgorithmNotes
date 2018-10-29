/*
题目描述
给定一长度为N的整数序列(a1,a2,…,aN)，将其划分成多个子序列（此问题中子序列是连续的一段整数）
满足每个子序列中整数的和不大于一个数B，设计一种划分方法，最小化所有子序列中最大值的和
说明其具有优化子结构及子问题重叠性质
例如：序列长度为8的整数序列(2,2,2,8,1,8,2,1)，B=17，
可将其划分成三个子序列(2,2,2)，(8,1,8)以及(2,1)
则可满足每个子序列中整数和不大于17，所有子序列中最大值的和12为最终结果
解题思路
设`A[i,j] = (ai,a[i+1],...,aj)`，`r(i,j)`表示`A[i,j]`在某种划分下所有子序列最大值的最小和  
在`k(i<=k<j)`处划分出一个子序列，得到`A[k+1,j]`，则  
`r(i,j) = min{r(i,k) + max(A[k+1,j])} ,    sum(A[k+1,j]) <= B, 1 <= i <= j <= n, i-1 <= k < j`  
原问题的最优解为  
`r(1,n) = min{r(1,k) + max(A[k+1,n])} ,    sum(A[k+1,n]) <= B, 0 <= k < n, n >= 1          `  
`r(1,n)`的最优解包含`r(1,k)`的最优解，  
问题的最优解包含子问题的最优解，且划分的子问题具有重叠性
*/

#include<iostream>
#include<vector>

using namespace std;

// 求子序列A[i,j] = (ai,a[i+1],...,aj)的和
int sum(vector<int> A, int i, int j)
{
	int res = 0;
	for(int k=i-1; k<j; ++k)
		res += A[k];

	return res;
}
// 求子序列A[i,j] = (ai,a[i+1],...,aj)的最大值
int maxe(vector<int> A, int i, int j)
{
	int res = A[i-1];
	for(int k=i; k<j; ++k)
	{
		if(A[k] > res)
			res = A[k];
	}

	return res;
}

int solve(vector<int> A, int B)
{
	int n = A.size();
	int r[n+1];
	int maxs = sum(A, 1, n) + 1;

	r[0] = 0;
	r[1] = A[0];

	for(int i=2; i<=n; ++i)
	{
		int tmp = maxs;
		for(int k=0; k<i; ++k)
		{
			if(sum(A, k+1, i) <= B)
			{
				tmp = min(tmp, r[k] + maxe(A, k+1, i));
			}
		}

		r[i] = tmp;
	}

	return r[n];
}

int main()
{
	vector<int> A{2,2,2,8,1,8,2,1};
	int B = 17;
	cout << solve(A, B) << endl;
}
