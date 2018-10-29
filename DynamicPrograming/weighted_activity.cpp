/*
#### 题目描述
给定`𝑛`个活动，活动`𝑎_𝑖`表示为一个三元组`(𝑠_𝑖,𝑓_𝑖,𝑣_𝑖)`  
其中`𝑠_𝑖`表示活动开始时间，`𝑓_𝑖`表示活动的结束时间，`𝑣_𝑖`表示活动的权重  
带权活动选择问题是选择一些活动使得任意被选择的两个活动`𝑎_𝑖`和`𝑎_𝑗`执行时间互不相交  
即区间`[𝑠_𝑖,𝑓_𝑖]`和`[𝑠_𝑗,𝑓_𝑗]`互不重叠，并且被选择的活动的权重和最大  
请设计一种方法求解带权活动选择问题

#### 解题思路
对所有活动按结束时间进行排序
设dp(i)表示活动a_1到a_i所选活动的最优解
此时分为两种情况选活动a_i和不选活动a_i
dp(i) = max{dp(i-1), dp(k) + v_i} ，  0 < k < i
a_k为距离a_i最近且与其不相交的活动
*/

#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>

using namespace std;

struct Activity
{
	int s;
	int f;
	int v;

	const bool operator < (const Activity a) const
	{
		return f < a.f;
	}

	Activity(int s, int e, int w): s(s), f(e), v(w){}
};

int solve(vector<Activity> a)
{
	int n = a.size();
	int r[n+1];

	r[0] = 0;
	r[1] = a[0].v;

	for(int i=2; i<=n; ++i)
	{
		int k = i - 1;
		while(k > 0 && a[k-1].f > a[i-1].s)	
			--k;
		r[i] = max(r[i-1], r[k] + a[i-1].v);
	}

	return r[n];
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
	srand((unsigned)time(NULL));
	for(int i=0; i<n; ++i)
	{
		int s = random();
		int fs = random();
		int v = random();
		Activity a(s, s + fs, v);
		res.push_back(a);
	}

	return res;
}

void printActivities(vector<Activity> a)
{
	for(auto e : a)
	{
		cout << "(" << e.s << "," << e.f << "," << e.v << ")" << endl;
	}
}

int main()
{
	cout << "带权活动的选择问题" << endl;

	vector<Activity> a = randActivities();
	sort(a.begin(), a.end());
	printActivities(a);

	cout << solve(a) << endl;
}