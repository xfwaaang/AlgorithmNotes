#### 题目描述
在`8x8`格的国际象棋盘上摆放八个皇后，使其不能互相攻击，即任意两个  
皇后不能处于同一行、同一列或同一斜线上，问有多少种摆法？

#### 解题思路


#### 代码实现

[code](/BacktrackingRecursive/eight_queens.cpp)

```
#include<iostream>

using namespace std;

const int n = 8;

int total = 0;

int c[n];

bool is_ok(int row)
{
	for(int i=0; i < row; ++i)
	{
		if(c[row] == c[i] || row - c[row] == i - c[i] || row + c[row] == i + c[i])
		{
			return false;
		}
	}

	return true;
}

void queen(int row)
{
	if(row == n)
	{
		total++;
	}
	else
	{
		for(int col=0; col<n; ++col)
		{
			c[row] = col;
			if(is_ok(row))
			{
				queen(row + 1);
			}
		}
	}
}

int main()
{
	queen(0);
	cout << total << endl;
}
```