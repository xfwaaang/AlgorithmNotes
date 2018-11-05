#### 题目描述
给定直线上 2n个点的序列P[1,2,… ,2n]，每个点 P[i]要么是白点要么是黑点，其中共有n个白点和 n个黑点  
相邻两个点之间距离均为1，请设计一个算法将每个白点与一黑点相连，使得连线的总长度最小  例如，图中有4个白点和4个黑点，以图中方式相连，连线总长度为1+1+1+5=8  

<img src="/Assets/mini_length_greedy.png" width="300" height="60" align="center">

#### 解题思路
不断地找当前最短的连线，并记录已经连过的点，将所有的连线加起来得到最终结果  
目前不会证明，因此不知道是否正确

#### 代码实现

[code](/GreedyAlgorithm/mini_length.cpp)
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
		flag[i] = true;
		flag[j] = true;
	}
	
	return res;
}
```
