/*
求两个整数的最小公倍数与最大公约数
最小公倍数 = 两整数的乘积 / 最大公约数
*/

#include <iostream>
#include"../util.h"

using namespace std;

/*
求两个整数的最大公约数
*/

/*
穷举法
1. k = 1；
2. 若a、b能同时被k整除，则t = k；
3. k++
4. 若k <= a(或b)，执行 2
5. 若k > a（或b），则t即为最大公约数
*/
int gcd_exhaustion(int a, int b)
{
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

/*
穷举法改进：
1. k = a(或b)
2. 若a、b能同时被k整除，则k为最大公约数
3. k--，执行 2
*/
 int gcd_exhaustion_better(int a, int b)
 {
 	int k = a < b ? a : b;
 	while(!(a % k == 0 && b % k == 0))
 		k--;
 	return k;
 }

 /*
 辗转相除法
 1. a%b得余数c
 2. 若c = 0，则b为最大公约数
 3. 若c ！= 0，则a = b，b = c，执行 1
 */
 // 迭代
int gcd_divide_iterative(int a, int b)
{
	int c;
	while(b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

// 递归
int gcd_divide_recursive(int a, int b)
{
	return b == 0 ? a : gcd_divide_recursive(b, a%b);
}

/*
循环相减法
1. 若a > b，则a = a - b
2. 若a < b，则b = b - a
3. 若a = b，a（b）即为最大公约数
4. 若a ！= b，执行 1
*/
int gcd_subtraction(int a, int b)
{
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

int main()
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 100; ++i)
	{
		int a = random(1, 100);
		int b = random(1, 100);

		cout << "a = " << a << "	b = " << b
		<< "		exhaustion: " << gcd_exhaustion(a, b) 
		<< "		exhaustion_better: " << gcd_exhaustion_better(a, b) 
		<< "		divide_iterative: " << gcd_divide_iterative(a, b) 
		<< "		divide_recursive: " << gcd_divide_recursive(a, b)
		<< "		subtraction: " << gcd_subtraction(a, b) 
		<< endl;

	}

	return 0;
}