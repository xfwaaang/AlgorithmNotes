#### 题目描述
给定两个字符串语句A和B，单词以空格分开，若某个单词在其中一个语句中仅出现一次  
且不在另一个语句中出现，则该单词称为 uncommon word，求出所有的 uncommon word

#### 代码实现

即求A和B中，出现一次的单词

```cpp
vector<string> uncommonFromSentences(string A, string B) 
{
    vector<string> res;
    unordered_map<string, int> help;
    istringstream iss(A + " " + B);
    string word;
    
    while(iss >> word)  ++help[word];
    for(auto e : help)  if(e.second == 1)   res.push_back(e.first);
    
    return res;
}
```