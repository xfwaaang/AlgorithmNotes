#### 题目描述
判断一个整数是否为回文数

#### 代码实现

[code](/Math/is_palindrome.cpp)

```cpp
bool isPalindrome(int x)
{
	if(x < 0)
		return false;

	int reverse = 0;
	int tmp = x;
	while(tmp)
	{
		reverse = reverse * 10 + tmp % 10;
		tmp /= 10;
	}
	return x == reverse;
}
```