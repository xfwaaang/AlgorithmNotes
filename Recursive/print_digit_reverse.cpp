/*
题目描述：
逆序输出正整数的各位数
*/

#include<iostream>

using namespace std;

void printDigitReverse(unsigned int n)
{
	cout << n % 10 ;
	if(n >= 10)	
		printDigitReverse(n / 10);
}

int main()
{
	printDigitReverse(12345);
	cout << endl;
}