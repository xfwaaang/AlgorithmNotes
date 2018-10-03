/*
题目描述：
有两个有序数组nums1和nums2，长度分别为m和n。 
找到两个有序数组的中位数，nums1和nums2不能都为空。
要求时间复杂度：O(log(m+n))
*/

#include<iostream>
#include<vector>

using namespace std;

// m = n
double median(int a[], int n)
{
	if(n % 2)
		return a[n/2];
	else
		return (a[n/2] + a[n/2-1]) / 2.0;
}

int main()
{
	cout << "求两个有序数组的中位数" << endl;
	vector<int> a{1, 2, 5};
	vector<int> b{3, 4};
	
	return 0;
}