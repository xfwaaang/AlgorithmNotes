#include<iostream>

using namespace std;

int partition(int A[], int s, int e)
{
	int pivot = A[s];

	while(s < e)
	{
		while(s < e && A[e] >= pivot)
			--e;
		A[s] = A[e];

		while(s < e && A[s] <= pivot)
			++s;
		A[e] = A[s];
	}

	A[e] = pivot;

	return s;
}

int findKth(int A[], int s, int e, int k)
{
	// 一次划分后基准元素最终的位置
	int pivot = partition(A, s, e);
	// 基准元素在当前数组中的相对位置，即数组的第pos小元素
	int pos = pivot - s + 1;

	if(pos == k)
	{
		return A[pivot];
	}
	else if(pos < k)
	{
		return findKth(A, pivot + 1, e, k - pos);
	}
	else
	{
		return findKth(A, s, pivot - 1, k);
	}
}

int main()
{
	int a[] = {2, 1, 3, 5, 4, 2, 3}; 
	cout << findKth(a, 0, 6, 3) << endl;

	return 0;
}