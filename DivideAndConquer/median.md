#### 题目描述

有两个有序数组`nums1`和`nums2`，长度分别为`m`和`n`。   
找到两个有序数组的中位数，`nums1`和`nums2`不能都为空。  
要求时间复杂度：`O(log(m+n))` 

#### 算法描述
方法一：  
求中位数可以转化为求有序数组的第`k`个元素  
用 `getKth(k)` 表示两个有序数组的第 `k` 小元素  

1. 若`m+n`为奇数，中位数为 `getKth((m+n)/2)`
2. 若`m+n`为偶数，中位数为 `(getKth((m+n)/2) + getKth((m+n-1)/2)) / 2`
  
求两个有序数组(`a`和`b`)的第`k`小元素  
1. 比较`a[k/2]`与`b[k/2]`，去除较小者数组的前 `k/2` 个元素，得到两个新的数组
2. 递归地执行步骤`1`  

方法二：  
首先求出两个数组的中位数`a = nums1[m/2], b = num2[n/2]`  
1. 若`a = b`，则中位数等于a
2. 若`a < b`, 则中位数在`nums1[m/2:m-1]`和`nums1[0:n/2]`中
3. 若`a > b`，则中位数在`nums1[0:m/2]`和`nums2[n/2:n-1]`中

#### 时间复杂度
`O(log(m+n))`

#### 代码实现

[源代码](/DivideAndConquer/median.cpp)

```cpp
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
```