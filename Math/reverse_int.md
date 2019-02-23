#### 题目描述
翻转一个整数  
ex：x = 123，return	321  
ex：x = -918，return -819  

#### 代码实现

[code](/Math/reverse_int.cpp)

```cpp
int reverse(int x)
{
	int temp = abs(x);
	int res = 0;

	while(temp)
	{
		res = res * 10 + temp % 10;
		temp /= 10;
	}

	return x > 0 ? res : -res;
}

```