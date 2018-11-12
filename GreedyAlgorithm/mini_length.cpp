#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int solve_1(vector<int> a)
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

		res += j - i;
		// i和j已被连接
		flag[i] = true;
		flag[j] = true;
	}

	return res;
}

int solve_2(vector<int> a)
{
	int res = 0;
	// 存储入栈的白点和黑点
	stack<int> help1;
	// 存储入栈的白点和黑点的位置
	stack<int> help2;
	int n = a.size();

	for(int i=0; i<n; ++i)
	{
		if(help1.empty() || (!help1.empty() && a[i] == help1.top()))
		{
			// 如果help1为空或者help1栈顶的点颜色与当前点a[i]的颜色相同，则
			// 将a[i]入栈help1，i入栈help2
			help1.push(a[i]);
			help2.push(i);
		}
		else if(!help1.empty() && a[i] != help1.top())
		{
			// 如果当前点a[i]的颜色与help1栈顶的点颜色不同，则弹出help1栈顶的点
			help1.pop();
			// help2.top()记录与当前点a[i]匹配点的位置
			res += i - help2.top();
			// 将匹配点的位置弹出
			help2.pop();
		}
	}

	return res;
}

int main()
{
	// 1代表黑点，0代表白点
	// vector<int> a{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1};
	vector<int> a{1, 1, 0, 1, 0, 0, 0, 1};

	cout << solve_1(a) << endl;
	cout << solve_2(a) << endl;
}