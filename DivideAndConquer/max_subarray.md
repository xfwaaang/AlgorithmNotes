#### 题目描述
在具有最大总和的数组（包含至少一个数字）中查找连续的子数组  
例如，给定数组[-2,1，-3,4，-1,2,1，-5,4]  
连续的子阵列[4，-1,2,1]具有最大的和为6  

#### 解题思路
将数组分为左右两部分，分别求左半部分、右半部分的最大子数组和  
及中间相邻连续部分的最大子数组和  
时间复杂度：O(nlogn)  
贪心法求解：[最大子数组和](/GreedyAlgorithm/max_subarray.md)

#### 代码实现

[code](/DivideAndConquer/max_subarray.cpp)

```
int solve(int A[], int s, int e)
{
	if(s == e)
	{
		return A[s];
	}
	else if(s > e)
	{
		return 0;
	}

	int m = (s + e) / 2;
	return max(max(solve(A, s, m), solve(A, m+1, e)), merge(A, s, m, e));
}
```

```
int merge(int A[], int s, int m, int e)
{
	int sum = A[m];
	int max_left = A[m];
	int max_right = A[m+1];
	for(int i=m-1; i>=s; --i)
	{
		sum += A[i];
		max_left = max(max_left, sum);
	}

	sum = A[m+1];
	for(int i=m+2; i<=e; ++i)
	{
		sum += A[i];
		max_right = max(max_right, sum);
	}

	return max_left + max_right;
}
```