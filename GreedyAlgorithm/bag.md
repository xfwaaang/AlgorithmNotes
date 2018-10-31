#### 题目描述
给定`n`个物品，物品价值分别为`P1,P2,…,Pn`,物品重量分别为`W1,W2,…,Wn`,背包容量为M  
每种物品可部分装入到背包中。输出`X1，X2,…,Xn, 0<=Xi<=1`使得背包内的物品价值最大  
试设计一个算法求解该问题，并分析算法的正确性

#### 解题思路
将物品按单位价值排序，依次向背包中尝试添加具有最大单位价值的物品  
若背包容量足够，则将整个物品加入，否则加入部分该物品

#### 代码实现

[code](/GreedyAlgorithm/bag.cpp)
```
struct Good
{
	float p;	// 物品价值
	float w;	// 物品重量

	Good(float p, float w): p(p), w(w){}

	const bool operator < (const Good g) const
	{
		return p / w < g.p / g.w;
	}
};
```

```
float solve(vector<Good> goods, int m)
{
	int res = 0;
	int curr_m = m;
	int n = goods.size();

	sort(goods.begin(), goods.end());

	for(int i=0; i<n; ++i)
	{
		if(curr_m >= goods[i].w)
		{
			res += goods[i].p;
			curr_m -= goods[i].w;
		}
		else
		{
			res += curr_m * (goods[i].p / goods[i].w);
			break;
		}
	}

	return res;
}
```