#include<iostream>
#include"../util.h"

using namespace std;

int solve(vector<int> a)
{
	int res = 0;
	int n = a.size();
	int j = 0;
	bool flag[n] = {false};

	for(int i=0; i<n; ++i)
	{
		if(flag[i])	continue;

		j = i + 1;
		while(j < n && a[j] == a[i] || flag[j])	++j;
		if(j == n)	break;

		cout << i << "," << j << endl;

		res += j - i;
		flag[i] = true;
		flag[j] = true;
	}
	return res;
}

int main()
{
	// 1代表黑点，0代表白点
	vector<int> a{1, 0, 0, 1, 0, 1, 0, 1};

	cout << solve(a) << endl;
}