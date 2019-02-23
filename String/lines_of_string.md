#### 题目描述
我们要将给定字符串S的字母从左到右写成行。每行最大宽度为100个单位  
如果写一个字母会导致该行的宽度超过100个单位，则会写入下一行  
给出一个数组, 其中widths [0]是'a'的宽度，widths [1]是'b'的宽度，...，widths [25]是'z'的宽度  
现在回答两个问题：S中至少有一个字符有多少行，最后一行使用的宽度是多少？  
将答案作为长度为2的整数列表返回  

#### 代码实现

[code](/String/lines_of_string.cpp)

```cpp
vector<int> numberOfLines(vector<int>& widths, string S)
{
    vector<int> a;
    int units = 0;
    int lines = 1;
    int i = 0;
    
    while(i < S.size())
    {
        int curr = units + widths[S[i]-'a'];
        if(curr <= 100)
        {
            units = curr;
        }
        else
        {
            units = widths[S[i]-'a'];
            lines++;
        }
        
        i++;
    }
    
    a.push_back(lines);
    a.push_back(units);
    
    return a;
}
```