/*
题目描述：
假设您有一个数组，其中第i个元素是第i天给定股票的价格。 
设计一个算法来找到最大的利润。
您可以根据需要完成尽可能多的交易（即多次买入和卖出一次股票）。
但是，您不得同时进行多笔交易（即您必须在再次购买之前出售股票）。
*/

#include<iostream>
#include<vector>
#include"util.h"

using namespace std;

/*
判断相邻元素是否递增，因为连续递增可以看作一次买入卖出操作，统计所有递增量
*/
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

int main()
{
	vector<int> randomArray = genRandomArray(4, 0, 4);

	for (int i = 0; i < randomArray.size(); ++i)
	{
		cout << randomArray[i] << " ";
	}
	cout << endl;
	cout << "max_profit: " << maxProfit(randomArray) << endl;

	return 0;
}