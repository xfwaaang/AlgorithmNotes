#### 题目描述
将英文单词转换为小写状态，如：  
Hello - hello  
love&OK - love&ok  
LONEly - lonely  

#### 代码实现

[code](/String/to_low_case.cpp)

```
string toLowCase(string str)
{
	for(int i=0; i<str.size(); ++i)
	{
		if(str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
	}
	return str;
}

string toLowCase_2(string str)
{
	for(char& c : str)
		if(c >= 'A' && c <= 'Z')	c += 32;
	return str;
}
```