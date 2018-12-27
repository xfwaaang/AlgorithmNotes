/*
题目描述：
写一个递归算法和一个迭代算法计算二项式系数
(x+y)^n = C(0,n) * x^0 * y^n + C(1,n) * x^1 * y^(n-1) + ... + 
C(m,n) * x^m * y^(n-m) + ... + C(n,n) * x^n * y^0

解题思路：
C(m,n) = C(m,n-1) + C(m-1,n-1)
	   = n! / (m!(n-m)!)
*/

#include<iostream>
#include"../util.h"

using namespace std;

/*
递归算法
C(m,n) = C(m,n-1) + C(m-1,n-1)
*/

int fun(int m, int n)
{
	if(m > n)
		throw "invalid arguments";

	if(m == n)
		return 1;
	if(m == 0)
		return 1;
	if(n == 1)
		return 1;

	return fun(m, n-1) + fun(m-1, n-1);
}

/*
迭代算法
C(m,n) = n! / (m!(n-m)!)
*/

/*
求n的阶乘n!
*/
int fac(int n)
{
	if(n == 0)
		return 1;
	int res = 1;
	for(int i=n; i > 1; --i)
		res *= i;

	return res;
}

int fun_2(int m, int n)
{
	if(m > n)
		throw "invalid arguments";

	int x = fac(n);
	int y = fac(m);
	int z = fac(n-m);

	return x / (y * z);
}


int main()
{
	vector<int> a = genRandomArray(2, 0, 10);
	int m = min(a[0], a[1]);
	int n = max(a[0], a[1]);
	cout << "计算二项式系数" << endl;
	cout << "m = " << m << "," << "n = " << n << endl;
	cout << "递归算法：" << endl;
	cout << fun(m, n) << endl;

	cout << "迭代算法：" << endl;
	cout << fun_2(m, n) << endl;
}