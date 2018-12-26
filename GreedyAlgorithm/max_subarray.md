#### 题目描述
在具有最大总和的数组（包含至少一个数字）中查找连续的子数组  
例如，给定数组[-2,1，-3,4，-1,2,1，-5,4]  
连续的子阵列[4，-1,2,1]具有最大的和为6  
时间复杂度：O(n)

#### 解决思路
采用贪心算法的策略 
1. 从头开始累加，直到和sum为负
2. sum < 0，表示不能给数组带来正收益，应舍弃
3. 统计最大的sum  

分治法求解：[最大子数组和](/DivideAndConquer/max_subarray.md)
  
#### 代码实现

[源代码](/GreedyAlgorithm/max_subarray.cpp)

```
int maxSubArray(int A[], int n)
{
	int sum = A[0];
	int maxSum = A[0];
	for (int i = 1; i < n; ++i)
	{
		if(sum < 0)
			sum = 0;
		sum += A[i];
		maxSum = max(sum, maxSum);
	}
	return maxSum;
}

```

另一种写法
```
int maxSubArray(int A[], int n)
{
	int max = A[0];
	int tmp = 0;

	for(int i=0; i<n; ++i)
	{
		if(tmp > 0)
			tmp += A[i];
		else
			tmp = A[i];

		if(tmp > max)
			max = tmp;
	}

	return max;
}
```