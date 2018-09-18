#ifndef util_h
#define util_h

#include<vector>
#include<iostream>
#include<ctime>
#include<cstdlib>

template<class T>
void swap(T a[], int i, int j)
{
	T t = a[i];
	a[i] = a[j];
	a[j] = t;
}

template<class T>
void swap(std::vector<T> &A, int i, int j)
{
	T t = A[i];
	A[i] = A[j];
	A[j] = t;
}

template<class T>
void printArray(T a[], int n)
{
	for(int i=0; i<n; ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

template<class T>
void printArray(std::vector<T> a)
{
	for(T i=0; i<a.size(); ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

/*
生成[min,max]之间的随机数
*/
int random(int min = 0, int max = 100)
{
	if(min > max)
		throw "Invalid arguments";
	
	return rand() % (max-min+1) + min;
}

/*
生成一个长度为n的随机数组，每个数在[min,max]之间
*/
std::vector<int> genRandomArray(int n = 10, int min = 0, int max = 100)
{
	if (n < 1 || min > max)
		throw "Invalid arguments";

	srand((unsigned)time(NULL));
	std::vector<int> randomArray(n);
	for (int i = 0; i < n; ++i)
	{
		randomArray[i] = random(min, max);
	}

	return randomArray;
}

/*
取最小值
*/
int min(int x, int y)
{
	return x < y ? x : y;
}

/*
取最大值
*/
int max(int x, int y)
{
	return x > y ? x : y;
}

/*
获取数组的长度
*/
template<class T>
int length(T& array)
{
	return sizeof(array) / sizeof(array[0]);
}


#endif
