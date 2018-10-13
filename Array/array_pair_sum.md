#### 题目描述
给定一个2n个整数的数组，你的任务是将这些整数分组为n对整数  
比如说（a1，b1），（a2，b2），...，（an，bn）  
求所有min（ai， bi）之和的最大值  
Input: [1,4,3,2]  
Output: 4  
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

#### 代码实现

[源代码](/Array/array_pair_sum.cpp)

```
int arrayPairSum(vector<int>& a)
{
	int res = 0;
	quickSort(a);
	for(int i=0; i<a.size(); i += 2)
		res += a[i];
	return res;
}
```