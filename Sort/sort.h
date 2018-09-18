#ifndef sort_h
#define sort_h

#include<vector>


void swap(std::vector<int>& a, int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

// 插入排序
// 每次将一个待排序的记录，按其关键字大小插入到前面已经排好序的子序列中，直到全部记录插入完成

/*
直接插入排序
边比较边移动元素直到找到待插入元素的位置，最后插入
时间复杂度：O(n^2)
空间复杂度：O(1)
稳定
比较次数：O(n)~O(n^2)
*/

void insertSort(std::vector<int>& a)
{
	for(int i=1; i<a.size(); ++i)
	{
		int tmp = a[i];
		int j = i - 1;
		while(j >= 0 && tmp < a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
	}
}


/*
折半插入排序
将比较和移动操作分离开，先折半查找出待插入元素的位置，再统一移动待插入位置之后的所有元素
时间复杂度：O(n^2)
空间复杂度：O(1)
稳定
比较次数：O(nlogn)
*/

void binaryInsertSort(std::vector<int>& a)
{
	int low, high, mid, key;

	for(int i=1; i<a.size(); ++i)
	{
		low = 0;
		high = i - 1;
		key = a[i];
		
		while(low <= high)
		{
			mid = (low + high) / 2;
			if(key > a[mid])
				low = mid + 1;
			else
				high = mid - 1;
		}

		for(int j=i-1; j>high; --j)
			a[j+1] = a[j];

		a[high+1] = key;
	}
}

// 选择排序
// 选择待排序列中最小或最大的元素作为有序子序列的尾元素，直到待排序列为一个元素

/*
简单选择排序
时间复杂度：O(n^2)
空间复杂度：O(1)
不稳定
*/
void selectSort(std::vector<int> &a)
{
	for(int i=0; i<a.size()-1; ++i)
	{
		int min_pos = i;
		for(int j=i+1; j<a.size(); ++j)
			if(a[min_pos] > a[j])
				min_pos = j;

		if(min_pos != i)
			swap(a, min_pos, i);
	}
}

/*
堆排序

以升序排序为例

a.建立大根堆
b.输出堆顶元素，即交换堆底元素与堆顶元素
c.将剩余元素调整为大根堆

时间复杂度：O(nlogn)
空间复杂度：O(1)
不稳定
*/

/*
自下往上调整k节点
*/
void adjustDown(std::vector<int> &a, int k, int n)
{
	// k的左孩子节点
	int left = 2 * k + 1;
	while(left < n)
	{
		// 父节点（k）与最大的子节点比较，若小于则交换
		int max_child = ((left+1) < n && a[left+1] > a[left]) ? left+1 : left;
		if(a[k] < a[max_child])
		{
			swap(a, k, max_child);
			k = max_child;
			left = 2 * k + 1;
		}
		else
			break;
	}
}

/*
从最后一个非叶子节点开始调整，最终建立大根堆
*/
void buildMaxHeap(std::vector<int> &a, int n)
{
	for(int i=n/2; i>=0; --i)
		adjustDown(a, i, n);
}

void heapSort(std::vector<int> &a)
{
	int n = a.size();
	buildMaxHeap(a, n);
	for(int i=n-1; i>0; --i)
	{
		swap(a, 0, i);
		adjustDown(a, 0, i);
	}
}


// 归并排序

// 递归形式的归并排序是基于分治的思想
// 首先将待排序列分成若干子序列
// 然后递归地对子序列进行排序
// 最后将已排序子序列合并

/*
二路归并排序
时间复杂度：O(nlogn)
空间复杂度：O(n)
稳定
*/

void merge(std::vector<int> &a, int l, int m, int r)
{
	std::vector<int> b(a);

	int i = l;
	int j = m + 1;
	int k = l;

	while(i <= m && j <= r)
	{
		if(b[i] <= b[j])
			a[k++] = b[i++];
		else
			a[k++] = b[j++];
	}

	while(i <= m)	a[k++] = b[i++];
	while(j <= r)	a[k++] = b[j++];
}

// 有问题

// void merge_2(std::vector<int> &a, int l, int m, int r)
// {
// 	std::vector<int> b(r-l+1);

// 	int i = l;
// 	int j = m + 1;

// 	while(i <= m && j <= r)
// 	{
// 		if(a[i] <= a[j])
// 			b.push_back(a[i++]);
// 		else
// 			b.push_back(a[j++]);
// 	}

// 	while(i <= m)	b.push_back(a[i++]);
// 	while(j <= r)	b.push_back(a[j++]);

// 	int k = 0;
// 	for(int i=l; i<=r; ++i)
// 		a[i] = b[k++];
// }

void merge_sort(std::vector<int> &a, int l, int r)
{
	if(l < r)
	{
		int m = (l + r) / 2;
		merge_sort(a, l, m);
		merge_sort(a, m+1, r);
		merge_2(a, l, m, r);
	}
}

void mergeSort(std::vector<int> &a)
{
	merge_sort(a, 0, a.size()-1);
}




// 交换排序
// 根据两个元素关键字的比较结果来交换两个元素在序列中的位置

/*
冒泡排序
每趟冒泡都会使一个元素被移动到最终位置
时间复杂度：O(n^2)
空间复杂度：O(1)
稳定
*/
void bubbleSort(std::vector<int> &a)
{
	bool flag = false;	//一次冒泡过程没有发生一次交换，则序列已排序完成
	for(int i=0; i<a.size(); ++i)
	{
		flag = false;
		for(int j=a.size()-1; j>i; --j)
			if(a[j] < a[j-1])
			{
				swap(a, j-1, j);
				flag = true;
			}

		if(!flag)
			break;
	}
}


/*
快速排序
*/
int partition(std::vector<int>& a, int low, int high)
{
	int pivot = a[low];
	while(low < high)
	{
		while(low < high && a[high] >= pivot)	--high;
		a[low] = a[high];

		while(low < high && a[low] <= pivot)	++low;
		a[high] = a[low];
	}
	a[high] = pivot;
	return low;
}


void _quickSort(std::vector<int>& a, int low, int high)
{
	if(low < high)
	{
		int index = partition(a, low, high);
		_quickSort(a, low, index - 1);
		_quickSort(a, index + 1, high);
	}
}

void quickSort(std::vector<int>& a)
{
	_quickSort(a, 0, a.size()-1);
}


#endif