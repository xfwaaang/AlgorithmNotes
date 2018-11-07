#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> a)
{
	int res = 0;
	int n = a.size();
	int j = 0;
	bool flag[n] = {false};

	for(int i=0; i<n; ++i)
	{	
		// 如果当前点已被连接，直接进入下一次循环
		if(flag[i])	continue;

		j = i + 1;
		// 寻找距离当前点a[i]最近且没有被连接的与当前点不同颜色的点
		while(j < n && a[j] == a[i] || flag[j])	++j;
		if(j == n)	break;

		cout << i << "," << j << endl;

		res += j - i;
		// i和j已被连接
		flag[i] = true;
		flag[j] = true;
	}

	return res;
}

int main()
{
	// 1代表黑点，0代表白点
	vector<int> a{1, 1, 0, 1, 0, 0, 0, 1};

	cout << solve(a) << endl;
}