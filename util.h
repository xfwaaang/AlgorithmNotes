#ifndef util_h
#define util_h

#include<vector>
#include<ctime>
#include<cstdlib>

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
