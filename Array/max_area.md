#### 题目描述

给定n个非负整数a1，a2，...，an，其中每个表示坐标（i，ai）处的点  
绘制n条垂直线，使得线i的两个端点位于（i，ai）和（i，0）  
找到两条线，它们与x轴一起形成一个容器，这个容器装水量最多   
注意：容器不能倾斜

#### 代码实现

[源代码](/Array/max_area.cpp)

```
// 时间复杂度：O(n^2)
int maxArea(vector<int> &height)
{
	int max_area = 0;
	int len = height.size();
	for(int i = 0; i < len; ++i)
	{
		for (int j = i+1; j < len; ++j)
		{
			int area = min(height[i], height[j]) * (j - i);
			if(area > max_area)
				max_area = area;
		}
	}
	return max_area;
}

// 时间复杂度：O(n)
int maxArea_better(vector<int> &height)
{
	int max_area = 0;
	int n = height.size();
	int i = 0;
	int j = n - 1;
	while(i < j)
	{
		int area = min(height[i], height[j]) * (j - i);
		if(area > max_area)
			max_area = area;
		if(height[i] < height[j])
			i++;
		else
			j--;
	}
	return max_area;
}

```