#include<iostream>

using namespace std;

int merge(int A[], int s, int m, int e)
{
	int sum = A[m];
	int max_left = A[m];
	int max_right = A[m+1];
	for(int i=m-1; i>=s; --i)
	{
		sum += A[i];
		max_left = max(max_left, sum);
	}

	sum = A[m+1];
	for(int i=m+2; i<=e; ++i)
	{
		sum += A[i];
		max_right = max(max_right, sum);
	}

	return max_left + max_right;
}

int solve(int A[], int s, int e)
{
	if(s == e)
	{
		return A[s];
	}
	else if(s > e)
	{
		return 0;
	}

	int m = (s + e) / 2;
	return max(max(solve(A, s, m), solve(A, m+1, e)), merge(A, s, m, e));
}

int main()
{
	int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, -4};
	cout << solve(A, 0, 8) << endl;
}