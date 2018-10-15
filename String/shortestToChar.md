#### 题目描述
给定一个字符串S和一个字符C，C是S中的任一字符，求出S中每个字符与C的最小距离  
Input: S = "loveleetcode", C = 'e'  
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]

#### 代码实现

##### 方法一

遍历 S，设置两个指针 i 和 j ，分别从当前元素向两边移动，直到遇到字符 C  
若 S[i] != C ，则当前元素 S[k] 与 C 的最短距离为 j - k；  
若 S[j] != C ，则 S[k] 与 C 的最短距离为 k - i；
否则，S[k] 与 C 的最短距离为 min(j - k, k - i)

```
vector<int> shortestToChar(string S, char C) 
{
    vector<int> res;
    
    int i = 0;
    int j = 0;
    int n = S.size();
    
    for(int k=0; k<n; ++k)
    {
        i = k;
        j = k;

        while(i > 0 && S[i] != C)  --i;
        while(j < n-1 && S[j] != C)  j++;
        
        if(S[i] != C)  
           res.push_back(j - k);
        else if(S[j] != C)  
           res.push_back(k - i);
        else  
           res.push_back(min(j - k, k - i));
    }
    
    return res;
}
```

##### 方法二

设置 i 和 j，i 指向当前元素 S[k] 左边且距其最近的字符C的位置；j 指向 S[k] 右边且距其最近的字符C的位置  
遍历 S，遇到字符 C，更新 i 和 j，S[k] 与 C 的最短距离为 min(k-i, j-k)

```
vector<int> shortestToChar(string S, char C) 
{
    vector<int> res;
    
    int n = S.size();
    int i = -n;
    int j = 0;
    
    while(S[j] != C)  ++j;
    
    for(int k=0; k<n; ++k)
    {
        if(S[k] == C)
        {
            i = k;
            j = k + 1;
            while(j < n && S[j] != C)  ++j;
            if(j >= n)  j = 2 * n;
        }

        res.push_back(min(k - i, j - k));
    }
    
    return res;
}
```

##### 方法三

```
vector<int> shortestToChar(string S, char C) 
{
    int n = S.size();
    vector<int> res(n, n);
    int pos = -n;

    for (int i = 0; i < n; ++i) 
    {
        if (S[i] == C) pos = i;
        res[i] = min(res[i], abs(i - pos));
    }

    for (int i = n - 1; i >= 0; --i) 
    {
        if (S[i] == C)  pos = i;
        res[i] = min(res[i], abs(i - pos));
    }

    return res;
}
```

##### 方法四

```
vector<int> shortestToChar(string S, char C) 
{
    int n = S.size();
    vector<int> res(n, n);

    for (int i = 0; i < n; ++i) if (S[i] == C) res[i] = 0;

    for (int i = 1; i < n; ++i) res[i] = min(res[i], res[i - 1] + 1);

    for (int i = n - 2; i >= 0; --i) res[i] = min(res[i], res[i + 1] + 1);
    
    return res;
}
```