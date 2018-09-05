/*
题目描述：
flip：[1, 0, 0] -> [0, 0, 1]
invert: [0, 0, 1] -> [1, 1, 0]
先水平逆转图片矩阵，然后将0转换为1,1转换为0
*/

#include<iostream>
#include"../util.h"

using namespace std;

vector< vector<int> > flipAndInvertImage(vector< vector<int> >& A)
{
	int n = A.size();
	for(int i=0; i<n; ++i)
	{
		// flip
		for(int j=0; j<n/2; ++j)
		{
			int tmp = A[i][j];
			A[i][j] = A[i][n-1-j];
			A[i][n-1-j] = tmp;
		}

		// invert
		for(int j=0; j<n; ++j)
		{
			// A[i][j] = A[i][j] == 0 ? 1 : 0;
			A[i][j] ^= 1; 
		}
	}

	return A;
}

void printMatrix(vector< vector<int> > A)
{
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < A.size(); ++j)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	vector< vector<int> > A = genRandomMatrix();
	printMatrix(A);

	printMatrix(flipAndInvertImage(A));
}
