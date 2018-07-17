/*
给定一个数n（n >=2），判断是否为质数
*/

#include<iostream>
#include<cmath>
#include"../util.h"

using namespace std;

/*
最简单的方法
若n不能被2至n-1之间的任意一个数整除则为质数
*/

bool isPrime(int n){
    if(n < 2)
        return false;
    int i = 2;
    for(; i<n; i++){
        if(n%i == 0)
            return false;
    }

    return true;
}

/*
降低一些复杂度
计算至n/2或sqrt（n），即可判断是否为质数
*/

bool isPrime_other(int n){
    if(n < 2)
        return false;
    if(n == 2 || n == 3)
        return true;

    int m = sqrt(n);
    int i = 2;
    for(; i<=m; i++){
        if(n%i == 0)
            return false;
    }

    return true;
}

int main()
{
	for (int i = 0; i < 10000; ++i)
	{
		if (isPrime(i))
			cout << i << " ";
	}

	cout << endl;

	for (int i = 0; i < 10000; ++i)
	{
		if (isPrime_other(i))
			cout << i << " ";
	}
}