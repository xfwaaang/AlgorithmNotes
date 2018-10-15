#### 题目描述
假定有三个塔座：x，y，z，在塔座x上有n个直径大小不一的圆盘，它们按直径从大到小依次放在x上  
现要求将x上的圆盘移动到y上，并保持原样堆放。移动过程需遵循以下规则：  
（1）每次只能移动一个圆盘  
（2）圆盘可以放在x，y，z中任意一个上  
（3）不能将直径较大的圆盘放在较小的圆盘之上  

#### 解题思路
（1）以y为中介，将前n-1个圆盘移动到z上  
（2）将第n个圆盘移动到y上  
（3）以x为中介，将z上n-1个圆盘移动到y上  

#### 代码实现

[code](/Recursive/hanoi.cpp)


```
enum tower
{
	A = 'X',
	B = 'Y',
	C = 'Z'
};

// 将第n个圆盘从x上移动到y上
void move(int n, tower x, tower y)
{
	cout << "the disk " << n << " is moved from "
	<< char(x) << " to top of " << char(y) << endl;
}

// 将n个圆盘从x上移动到y上
void hanoi(int n, tower x, tower y, tower z)
{
	if(n)
	{
		hanoi(n-1, x, z, y);
		move(n, x, y);
		hanoi(n-1, z, y, x);
	}
}

```