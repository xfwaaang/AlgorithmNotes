/*
给定一个字符串s，返回“反向”字符串，其中不是字母的字符都保留在原位置，字母字符都反转它们的位置
Input: "ab-cd"
Output: "dc-ba"
Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
*/

#include<iostream>

using namespace std;

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

int main()
{
	string s = "a-bC-dEf-ghIj";

	cout << reverseOnlyLetters(s) << endl;
}