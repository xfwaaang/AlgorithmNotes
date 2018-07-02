/*
题目描述：
给定一个整数数组，除了一个元素外，每个元素都会出现两次。
找到那一个。 
注意：时间复杂度O(n)，空间复杂度O(1)

解决思路：
1.异或满足交换律
2.相同两个数异或为0
3.0异或一个数为那个数本身
将数组所有元素进行异或操作
*/

#include<iostream>
using namespace std;

int singleNumber(int A[], int n)
{
	int res = A[0];
	for (int i = 1; i < n; ++i)
	{
		res ^= A[i];
	}

	return res;
}

int main()
{
	int A[] = {10,2,2,3,4,3,4,5,6,5,6};
	cout << singleNumber(A, 11) << endl;
	return 0;
}