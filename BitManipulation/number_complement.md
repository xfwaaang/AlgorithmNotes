#### 题目描述
定正整数，输出其complement number，即翻转其二进制表示的位  
Input: 5    
Output: 2    
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

#### 解题思路
异或运算有以下特征  
1 ^ 1 = 0  
0 ^ 1 = 1

#### 代码实现

[源代码](/BitManipulation/number_complement.cpp)

```cpp
int findComplement(int num)
{
	int k = 1;
	while(num / k)
		k *= 2;

	return num ^ (k - 1);
}

/*
leetcode上别人实现的代码
*/
int findComplement_2(int num) 
{
    unsigned mask = ~0;
    while (num & mask) mask <<= 1;
    return ~mask & ~num;
}
```