#### 题目描述
求两个整数的最小公倍数与最大公约数  
最小公倍数 = 两整数的乘积 / 最大公约数

#### 代码实现

[code](/Math/lcm_gcd.cpp)

求两个整数的最大公约数

##### 穷举法
1. k = 1；
2. 若a、b能同时被k整除，则t = k；
3. k++
4. 若k <= a(或b)，执行 2
5. 若k > a（或b），则t即为最大公约数

```cpp
int gcd_exhaustion(int a, int b)
{
	if(a == 0)
		return b;
	if(b == 0)
		return a;

	int k = 1;
	int t = k;
	while(k <= a && k <= b)
	{
		if(a % k == 0 && b % k == 0)
			t = k;
		k++;
	}
	return t;
}
```

穷举法改进：
1. k = a(或b)
2. 若a、b能同时被k整除，则k为最大公约数
3. k--，执行 2

```cpp
int gcd_exhaustion_better(int a, int b)
 {
	if(a == 0)
		return b;
	if(b == 0)
		return a;

 	int k = a < b ? a : b;
 	// a % k || b % k
 	while(!(a % k == 0 && b % k == 0))
 		k--;
 	return k;
 }
```

##### 辗转相除法
又称为欧几里得算法

1. a%b得余数c
2. 若c = 0，则b为最大公约数
3. 若c ！= 0，则a = b，b = c，执行 1

- 迭代

```cpp
int gcd_divide_iterative(int a, int b)
{
	if(a == 0)
		return b;
	if(b == 0)
		return a;

	int c;
	while(b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}
```

- 递归

```cpp
int gcd_divide_recursive(int a, int b)
{
	if(a == 0)
		return b;
	if(b == 0)
		return a;

	return b == 0 ? a : gcd_divide_recursive(b, a%b);
}

```

##### 循环相减法

1. 若a > b，则a = a - b
2. 若a < b，则b = b - a
3. 若a = b，a（b）即为最大公约数
4. 若a ！= b，执行 1

```cpp
int gcd_subtraction(int a, int b)
{
	if(a == 0)
		return b;
	if(b == 0)
		return a;

	while(a != b)
	{
		if(a > b)
			a = a - b;
		else
			b = b - a;
		// cout << a << " " << b << endl;
	}
	return a;
}
```