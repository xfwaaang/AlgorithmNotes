#### 题目描述
输入一个仅含0或1数字的整数，将其表示的二进制转化为十进制

#### 代码实现
[code](/Math/binary2decimal.cpp)
```cpp
int solve(int a)
{
	int res = 0;
	int t = 1;

	while(a)
	{
		res += t * a % 10;
		a /= 10;
		t *= 2;
	}

	return res;
}
```