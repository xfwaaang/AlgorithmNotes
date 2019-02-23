#### 题目描述
逆序输出正整数的各位数

#### 代码实现

[code](/Recursive/print_digit_reverse.cpp)

```cpp
void printDigitReverse(unsigned int n)
{
	cout << n % 10 ;
	if(n >= 10)	
		printDigitReverse(n / 10);
}
```