#ifndef sort_h
#define sort_h

#include<vector>


void swap(std::vector<int>& a, int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = a[i];

	a[i] = 
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

void binaryInsertSort(vector<int>& a)
{

}

// 选择排序

/*
简单选择排序
*/

/*
堆排序
*/

// 归并排序


// 交换排序

/*
冒泡排序
*/



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