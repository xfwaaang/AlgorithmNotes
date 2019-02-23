#### 题目描述
有一个n阶楼梯，每次只能走一阶楼梯或两阶楼梯，问爬到第n阶楼梯共有多少种走法？
#### 解题思路
假设只剩最后一步爬到第n阶，那么只有两种情况
1. 只需爬一阶楼梯，表明之前已经爬到第n-1层
2. 爬两阶楼梯，表明之前已经爬到第n-2层

那么f(n) = f(n-1) + f(n-2)

#### 代码实现

[code](/DynamicPrograming/climb_stairs.cpp)

```cpp
int climbStairs(int n)
{
	if(n < 1)
		return 0;
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;

	int a[n+1];
	a[1] = 1;
	a[2] = 2;
	for(int i=3; i<=n; ++i)
	{
		a[i] = a[i-1] + a[i-2];
	}
	
	return a[n];
}
```