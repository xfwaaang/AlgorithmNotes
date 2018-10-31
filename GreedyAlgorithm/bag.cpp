#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

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

// m为背包容量
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

int main()
{

}