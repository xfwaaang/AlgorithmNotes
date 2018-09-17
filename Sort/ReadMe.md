### SortAlgorithm
排序算法总结

#### 插入排序

- 直接插入排序

边比较边移动元素直到找到待插入元素的位置，最后插入

> 时间复杂度：O(n^2), 空间复杂度：O(1)    
  稳定, 比较次数：O(n)~O(n^2)

```
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
```

- 折半插入排序

将比较和移动操作分离开，先折半查找出待插入元素的位置，再统一移动待插入位置之后的所有元素

> 时间复杂度：O(n^2), 空间复杂度：O(1)  
  稳定, 比较次数：O(nlogn)

```
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
```

#### 交换排序

#### 选择排序

#### 归并排序