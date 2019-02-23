#### 题目描述
计算x的二进制表示中1和0的个数

#### 代码实现

[code](/Math/bit_count.cpp)

```cpp
int binary1num(int x)
{
	int num = 0;

	while(x)
	{
		x = x & (x-1);
		num++;
	}

	return num;
}

int binary0num(int x)
{
	int num = 0;

	while(x+1)
	{
		x = x | (x+1);
		num++;
	}

	return num;
}
```