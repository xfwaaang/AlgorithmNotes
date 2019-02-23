#### 题目描述

假设您有一个数组，其中第i个元素是第i天给定股票的价格  
设计一个算法来找到最大的利润  
1.您可以根据需要完成尽可能多的交易（即多次买入和卖出一次股票）  
但是，您不得同时进行多笔交易（即您必须在再次购买之前出售股票）  
2.您只可以进行一次交易

#### 代码实现

[源代码](/Array/max_profit.cpp)

1. 可以进行多次交易

判断相邻元素是否递增，因为连续递增可以看作一次买入卖出操作，统计所有递增量

```cpp
int maxProfit(vector<int> &prices)
{
	int res = 0;
	int n = prices.size();

	if(n < 2)	return 0;

	for (int i = 1; i < n; ++i)
	{
		if(prices[i] > prices[i-1])
			res += prices[i] - prices[i-1];
	}

	return res;
}
```

2. 只可以进行一次交易

记录前i个元素中最小的股票价值

```
int maxProfit_other(vector<int> &prices)
{
	int n = prices.size();

	if(n < 2) return 0;

	int minPrice = prices[0];
	int maxProfit = 0;

	for(int i=1; i<n; ++i)
	{
		minPrice = min(minPrice, prices[i-1]);
		maxProfit = max(maxProfit, prices[i] - minPrice);
	}

	return maxProfit;
}
```