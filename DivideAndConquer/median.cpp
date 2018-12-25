/*
题目描述：
有两个有序数组nums1和nums2，长度分别为m和n。 
找到两个有序数组的中位数，nums1和nums2不能都为空。
要求时间复杂度：O(log(m+n))

算法描述：
求中位数可以转化为求有序数组的第K个元素  
用 getKth(k) 表示两个有序数组的第 k 小元素  

1. 若m+n为奇数，中位数为 getKth((m+n)/2)
2. 若m+n为偶数，中位数为 (getKth((m+n)/2) + getKth((m+n-1)/2)) / 2
  
求两个有序数组(a和b)的第k小元素  
1. 比较a[k/2]与b[k/2]，去除较小者数组的前 k/2 个元素，得到两个新的数组
2. 递归地执行步骤1

时间复杂度：
O(log(m+n))
*/

#include<iostream>
#include<vector>

using namespace std;

// 方法一

int getKth(vector<int>& v1, int start1, int end1, vector<int>& v2, int start2, int end2, int k)
{
	int n1 = end1 - start1 + 1;
	int n2 = end2 - start2 + 1;

	// 保证v1的长度最小
	if(n1 > n2)	return getKth(v2, start2, end2, v1, start1, end1, k);

	if(n1 == 0)	return v2[start2 + k - 1];

	if(k == 1)	return min(v1[start1], v2[start2]);

	// 防止数组长度小于 k/2
	int i = min(n1, k/2) + start1 - 1;
	int j = min(n2, k/2) + start2 - 1;

	if(v1[i] > v2[j])	
		return getKth(v1, start1, end1, v2, j + 1, end2, k - (j - start2 + 1));
	else	
		return getKth(v1, i+1, end1, v2, start2, end2, k - (i - start1 + 1));
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int n = nums1.size();
    int m = nums2.size();
    int left = (n + m + 1) / 2;
    int right = (n + m + 2) / 2;
    //将偶数和奇数的情况合并，如果是奇数，会求两次同样的 k 。
    return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5; 
}

// 方法二
// bug
int solve(int nums1[], int nums2[], int s1, int e1, int s2, int e2)
{
	int m1 = (s1 + e1) / 2;
	int m2 = (s2 + e2) / 2;
	int a = nums1[m1];
	int b = nums2[m2];

	if(s1 == e1)
	{
		return (a + b) / 2;
	}

	if(a == b)
	{
		return a;
	}
	else if(a < b)
	{
		return solve(nums1, nums2, m1, e1, s2, m2);
	}
	else
	{
		return solve(nums1, nums2, s1, m1, m2, e2);
	}
}

int main()
{
	cout << "求两个有序数组的中位数" << endl;
	vector<int> a{1, 2, 5, 8};
	vector<int> b{3, 4, 6};
	
	cout << findMedianSortedArrays(a, b) << endl;

	int nums1[] = {1, 2, 5, 8};
	int nums2[] = {3, 4, 6};
	// cout << solve(nums1, nums2, 0, 2, 0, 2) << endl;

	return 0;
}