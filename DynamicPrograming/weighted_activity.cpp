/*
#### 题目描述
给定`𝑛`个活动，活动`𝑎_𝑖`表示为一个三元组`(𝑠_𝑖,𝑓_𝑖,𝑣_𝑖)`  
其中`𝑠_𝑖`表示活动开始时间，`𝑓_𝑖`表示活动的结束时间，`𝑣_𝑖`表示活动的权重  
带权活动选择问题是选择一些活动使得任意被选择的两个活动`𝑎_𝑖`和`𝑎_𝑗`执行时间互不相交  
即区间`[𝑠_𝑖,𝑓_𝑖]`和`[𝑠_𝑗,𝑓_𝑗]`互不重叠，并且被选择的活动的权重和最大  
请设计一种方法求解带权活动选择问题

#### 解题思路
用`a[1,n] = (a1,a2,...,an)`表示`n`个活动，`a[k]`表示其中某个活动  
设`r(i,j)`表示从`a[i,j]`（`j-i+1`个活动）中所选活动的权值和的最大值  
在`a[i,j]`中选择某个活动`a[k]`，则  
`r(i,j) = max{r(i,k-1) + v[k] + r(k+1,j)} ,     i <= k <= j`  
所以原问题的最优解为  
`r(1,n) = max{r(1,k-1) + v[k] + r(k+1,n)} ,     1 <= k <= n`   
问题的最优解包含子问题的最优解且子问题具有重叠性  
需要注意的是任意两个所选活动不能相交
*/

#include<iostream>
#include<vector>

using namespace std;

struct Activity
{
	int start;
	int end;
	int weight;

	Activity(int s, int e, int w): start(s), end(e), weight(w){}
};

int solve(vector<Activity> a)
{
	int n = a.size();
	int r[n+1][n+1];
	
	int x, i, j, k, p, q, tmp;

	for(i=1; i<=n; ++i)
		r[i][i] = a[i].weight;

	for(i=1; i<=n; ++i)
	{
		for(j=0; j<i; ++j)
			r[i][j] = 0;
	}

	for(i=0; i<=n; ++i)
	{
		r[i][0] = 0;
		r[0][i] = 0;
	}

	for(x=1; x<=n-1; ++x)
	{
		for(i=1; i<=n-x; ++i)
		{
			j = i + x;

			tmp = -1;
			for(k=i+1; k<j; ++k)
			{
				p = k - 1;
				q = k + 1;
				while(p > i && a[k].start < a[p].end)	--p;
				while(q < j && a[k].end > a[q].start)	++q;
				tmp = max(r[i][p] + r[k][k] + r[q][j], tmp);
			}
			r[i][j] = tmp;

			cout << tmp << " ";
		}
		cout << endl;
	}

	return r[1][n];
}

int random(int min = 1, int max = 10)
{
	if(min > max)
		throw "Invalid arguments";
	
	return rand() % (max-min+1) + min;
}

vector<Activity> randActivities(int n = 10)
{
	vector<Activity> res;
	for(int i=0; i<n; ++i)
	{
		int r1 = random();
		int r2 = random();
		Activity a(i, i+r1, r2);
		res.push_back(a);
	}

	return res;
}

void printActivities(vector<Activity> a)
{
	for(auto e : a)
	{
		cout << "(" << e.start << "," << e.end << "," << e.weight << ")" << endl;
	}
}

int main()
{
	cout << "带权活动的选择问题" << endl;

	vector<Activity> a = randActivities();
	printActivities(a);

	cout << solve(a) << endl;
}