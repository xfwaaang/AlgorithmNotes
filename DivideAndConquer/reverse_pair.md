#### 题目描述
有一实数序列𝑎_1,𝑎_2,…,𝑎_𝑁，若𝑖<𝑗 且 𝑎_𝑖>𝑎_𝑗，则(𝑎_𝑖,𝑎_𝑗)构成了一个逆序对
请使用分治方法求整个序列中逆序对个数，并分析算法的时间复杂性
例如：序列(4,3,2)逆序对有(4,3)，(4,2)，(3,2)共3个

#### 算法描述
借鉴归并排序的思想，递归地求出两子序列中逆序对个数及左序列元素和右序列元素形成的逆序对个数
1. 将序列分成左右两个子序列，分别求其逆序对个数
2. 原序列的逆序对个数等于两个子序列逆序对个数加上左序列和右序列元素形成的逆序对个数
3. 递归地执行1和2两个步骤

#### 时间复杂度分析

T(n)=2T(n/2) + O(n)  
求左右序列元素的逆序对个数时间复杂度为O(n)  
分解的次数为O(logn)  
总时间复杂度为O(nlogn)

#### 代码实现

[源代码](/DivideAndConquer/reverse_pair.cpp)

```
int merge(vector<int>& a, int l, int m, int h)
{
	int count = 0;

	vector<int> b;

	int i = l;
	int j = m + 1;

	while(i <= m && j <= h)
	{
		if(a[i] > a[j])
		{
			b.push_back(a[j++]);
			// 左序列元素a[i] > a[j], 则左序列第i-m个元素与a[j]均可组成逆序对
			count += m - i + 1;
		}
		else	b.push_back(a[i++]);
	}

	while(i <= m)	b.push_back(a[i++]);
	while(j <= h)	b.push_back(a[j++]);

	for(int i=0; i<b.size(); ++i)
		a[i+l] = b[i];

	return count;
}

int countOfRP(vector<int>& a, int l, int h)
{
	if(l >= h)	return 0;
	int m = (l + h) >> 1;
	return countOfRP(a, l, m) + countOfRP(a, m+1, h) + merge(a, l, m, h); 
}

int solve(vector<int>& a)
{
	int n = a.size();

	if(n < 2)	return 0;

	return countOfRP(a, 0, n-1);
}
```