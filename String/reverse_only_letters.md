#### 题目描述

给定一个字符串s，返回“反向”字符串，其中不是字母的字符都保留在原位置，字母字符都反转它们的位置  
[917. Reverse Only Letters of LeetCode](https://leetcode.com/problems/reverse-only-letters/description/)

> Input: "ab-cd"   
  Output: "dc-ba"  
  Input: "a-bC-dEf-ghIj"  
  Output: "j-Ih-gfE-dCba"  
  Input: "Test1ng-Leet=code-Q!"  
  Output: "Qedo1ct-eeLg=ntse-T!"

#### 解题思路

设置i = 0和j = len-1，分别指向s的第一个字符和最后一个字符  
遍历s，遇到非字母字符++i或者--j，交换s的i和j位置的字符

#### 代码实现

[源代码](/DivideAndConquer/reverse_pair.cpp)

```
bool isAlpha(char c)
{
    if(c >= 'a' && c <= 'z')
        return true;
    else if(c >= 'A' && c <= 'Z')
        return true;
    
    return false;
 }
    
void swap(string &s, int i, int j)
{
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
    
string reverseOnlyLetters(string s) 
{
    int i = 0;
    int j = s.length() - 1;
    
    while(i < j)
    {
    	// 遇到非字母字符跳过
        while(i < j && !isAlpha(s[i]))  ++i;
        while(i < j && !isAlpha(s[j]))  --j;
        
        swap(s, i, j);
        
        ++i;
        --j;
    }
    
    return s;
}
```
