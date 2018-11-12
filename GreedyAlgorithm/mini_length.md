#### 题目描述
给定直线上 2n个点的序列P[1,2,… ,2n]，每个点 P[i]要么是白点要么是黑点，其中共有n个白点和 n个黑点  
相邻两个点之间距离均为1，请设计一个算法将每个白点与一黑点相连，使得连线的总长度最小  例如，图中有4个白点和4个黑点，以图中方式相连，连线总长度为1+1+1+5=8  

<img src="/Assets/mini_length_greedy.png" width="300" height="60" align="center">

#### 解题思路
##### 方法一  
从左向右遍历所有的点，不断地找当前最短的连线，并记录已经连过的点，将所有的连线加起来得到最终结果  
<img src="/Assets/mini_length_greedy_1.png" width="300" height="60" align="center">
##### 方法二  
利用栈来解决  
从左到右遍历所有的点，如果栈为空或者当前点的颜色与栈顶点颜色相同，则入栈  
如果当前点的颜色与栈顶点的颜色不同，则出栈，于是得到一对匹配的点对，计算其连线距离  
将所有匹配点对的连线距离相加，得到最终结果  
<img src="/Assets/mini_length_greedy.png" width="300" height="60" align="center">

#### 代码实现

[code](/GreedyAlgorithm/mini_length.cpp)  
方法一
```
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

		res += j - i;
		// i和j已被连接
		flag[i] = true;
		flag[j] = true;
	}
	
	return res;
}
```
方法二
```
int solve(vector<int> a)
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
```