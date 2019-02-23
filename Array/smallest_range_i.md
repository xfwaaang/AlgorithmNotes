#### 题目描述
给定一个整数数组A，对于每个整数A[i]  
我们可以选择任何x，其中-K <= x <= K，并将x加到A[i]  
得到数组B. 返回B的最大值和B的最小值之差  
Input: A = [1], K = 0  
Output: 0  
Explanation: B = [1]  

Input: A = [0,10], K = 2  
Output: 6  
Explanation: B = [2,8]  

Input: A = [1,3,6], K = 3  
Output: 0  
Explanation: B = [3,3,3] or B = [4,4,4]

#### 代码实现

[源代码](/Array/smallest_range_i.cpp)

```cpp
int smallestRangeI(vector<int> &A, int k)
{
	int maxx = A[0];
	int minn = A[0];

	for(int i=0; i<A.size(); ++i)
	{
		maxx = max(maxx, A[i]);
		minn = min(minn, A[i]);
	}

	int res = maxx - k - minn - k;

	if(res <= 0)	return 0;

	return res;
}

```