#### 题目描述
我们定义Perfect Number是一个正整数，它等于除了它自己之外的所有正除数的总和  
现在，给定一个整数n，编写一个函数，当它是一个完美数字时返回true，否则返回false  
Input: 28  
Output: True  
Explanation: 28 = 1 + 2 + 4 + 7 + 14

#### 代码实现

[code](/Math/perfect_number.cpp)

```cpp
bool isPerfectNumber(int x)
{
	if(x == 1)
		return false;

	int n = sqrt(x);
	int y = x - 1;
	for(int i=2; i<=n; ++i)
	{
		if(x % i == 0)
		{
			y = y - i - x / i;
		}
	}

	return !y;
}
```