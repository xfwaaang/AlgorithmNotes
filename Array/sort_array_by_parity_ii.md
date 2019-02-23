#### 题目描述
给定一个非负整数的数组A，A中的一半整数是奇数，一半是偶数  
对数组进行排序，使得A[i]为奇数时，i为奇数; A[i]是偶数时，i是偶数
满足此条件的任何数组均可
Input: [4,2,5,7]  
Output: [4,5,2,7]  
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

#### 代码实现

##### 方法一

1. 将A的所有偶数元素放在前面，奇数元素放在后面  
参考：[sort_array_by_parity](/Array/sort_array_by_parity.cpp)
2. 交换A前半部分奇数位置和后半部分偶数位置的元素

```cpp
vector<int> sortArrayByParityII(vector<int>& A) 
{
    int i = 0;
    int j = A.size() - 1;
    while(i < j)
    {
        while(i < j && A[i]%2 == 0) ++i;
        while(i < j && A[j]%2 != 0) --j;
        
        swap(A, i, j);
    }
    
    for(int i=1, j=A.size()-2; i<j; i+=2, j-=2) swap(A, i, j);
    
    return A;
}
```

##### 方法二

设置两个指针i和j，分别指向A的偶数位置和奇数位置，初始值i=0，j=1  
遍历数组A，若A[i]为偶数，则i+2；若A[j]为奇数，则j+2  
遇到不满足条件的i和j，交换i和j两个位置的元素

```cpp
vector<int> sortArrayByParityII(vector<int>& A) 
{
    int i = 0;
    int j = 1;
    int n = A.size();
    
    while(i < n && j < n)
    {
        while(i < n && A[i]%2 == 0) i += 2;
        while(j < n && A[j]%2 == 1) j += 2;
        
        if(i < n && j < n)  swap(A, i, j);
    }
    
    return A;
}
```

