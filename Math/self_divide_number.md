#### 题目描述
自分割数是一个可被其包含的每个数字整除的数字  
例如，128是自分割数，因为128％1 == 0,128％2 == 0，128％8 == 0  
此外，不允许自分割数包含数字零  
给定下限和上限数字，输出包含每个可能的自分割数列表，如果可能，包括边界

#### 代码实现

[code](/Math/self_divide_number.cpp)

```cpp
bool isSelfDividingNumber(int k)
{
	int tmp = k;
	while(tmp)
	{
		int x = tmp % 10;
		if(x == 0)
			return false;
		if(k % x != 0)
			return false;
		tmp /= 10;
	}
	return true;
}

vector<int> selfDividingNumbers(int left, int right)
{
	vector<int> res;
	for(int k=left; k<=right; ++k)
	{
		if(isSelfDividingNumber(k))
			res.push_back(k);
	}
	return res;
}
```