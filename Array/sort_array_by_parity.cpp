/*
题目描述：
给定一个非负整数数组A，返回一个由A的所有偶数元素组成的数组，后跟A的所有奇数元素。 
您可以返回满足此条件的任何答案数组。
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
*/

#include<iostream>
#include"../util.h"

using namespace std;

vector<int> sortArrayByParity(vector<int> &A)
{
	int l = 0;
	int r = A.size() - 1;
	while(l < r)
	{
		while(l < r && A[l] % 2 == 0)	++l;
		while(l < r && A[r] % 2 != 0)	--r;
		swap(A, l, r);
	}

	return A;
}

int main()
{
	vector<int> A = genRandomArray(7, 0, 9);
	printArray(A);
	vector<int> B = sortArrayByParity(A);
	printArray(B);
	return 0;
}