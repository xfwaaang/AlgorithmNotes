/*
题目描述：
给定𝑛座建筑物 𝐵[1, 2, … , 𝑛]，每个建筑物 𝐵[𝑖]表示为一个矩形，用三元组𝐵[𝑖]=(𝑎_𝑖,𝑏_𝑖,ℎ_𝑖)表示
其中𝑎_𝑖表示建筑左下顶点，𝑏_𝑖表示建筑的右下顶点，ℎ_𝑖表示建筑的高
请设计一个 𝑂(𝑛log𝑛)的算法求出这𝑛座建筑物的天际轮廓
例如，左下图所示中8座建筑的表示分别为
(1,5,11), (2,7,6), (3,9,13), (12,16,7), (14,25,3), (19,22,18), (23,29,13)和(24,28,4)
其天际轮廓如右下图所示可用9个高度的变化
(1, 11), (3, 13), (9, 0), (12, 7), (16, 3), (19, 18), (22, 3), (23, 13)和(29,0)表示
另举一个例子，假定只有一个建筑物(1, 5, 11)，其天际轮廓输出为2个高度的变化(1, 11), (5, 0)
假设B中n座建筑物已按x坐标排好序

算法描述：
借鉴归并排序的思想，递归的求出两个子数组的高度变化，然后将两个子数组的高度变化进行合并
主要处理高度变化重叠的部分，有点类似于归并排序的merge操作
1. 将B分成两等份C和D
2. 分别求C和D的高度变化，得到结果记为res(C)和res(D)
3. 合并res(C)和res(D)，得到B的解
4. 递归执行以上步骤
*/

#include<iostream>
#include<vector>

using namespace std;

struct Rec
{
	int a, b, h;
	Rec(int a, int b, int h): a(a), b(b), h(h) {}

	const bool operator < (const Rec rec) const
	{
		return a < rec.a;
	}
};

struct Coordinate
{
	int x, y;
	Coordinate(int x, int y): x(x), y(y) {}
};

void printCoordinate(vector<Coordinate> v)
{
	for(auto c : v)
		cout << "(" << c.x << ", " << c.y << ")" << " " ;

	cout << endl;
}

void printRec(vector<Rec> v)
{
	for(auto r : v)
		cout << "(" << r.a << ", " << r.b << ", " << r.h << ")" << " " ;

	cout << endl;
}

vector<Rec> genBuilding(vector<int> v)
{
	int n = v.size();
	vector<Rec> res;
	
	for(int i=0; i<v.size(); i+=3)
	{
		Rec rec(v[i], v[i+1], v[i+2]);
		res.push_back(rec);
	}

	return res;
}

/*
有bug
*/
vector<Coordinate> merge(vector<Coordinate>& v1, vector<Coordinate>& v2)
{
	vector<Coordinate> res;

	if(v1[v1.size()-1].x < v2[0].x)
	{
		res.insert(res.end(), v1.begin(), v1.end());
		res.insert(res.end(), v2.begin(), v2.end());
		return res;
	}
	else if(v1[0].x > v2[v2.size()-1].x)
	{
		res.insert(res.end(), v2.begin(), v2.end());
		res.insert(res.end(), v1.begin(), v1.end());
		return res;
	}
	
	int i = 0, j = 0;
	int h = 0;

	int flag = 0;

	if(v1[0].x < v2[0].x)
	{
		h = v1[0].y;
		flag = 0;

		Coordinate a(v1[0].x, h);
		res.push_back(a);
		i++;
	}
	else
	{
		h = v2[0].y;
		flag = 1;

		Coordinate b(v2[0].x, h);
		res.push_back(b);
		j++;
	}

	while(i < v1.size() && j < v2.size())
	{
		if(v1[i].x < v2[j].x)
		{
			if(flag == 0)
			{
				h = v1[i].y;
				Coordinate c(v1[i].x, h);
				res.push_back(c);
			}
			else
			{
				if(v1[i].y > h)
				{
					h = v1[i].y;
					flag = 0;
					Coordinate c(v1[i].x, h);
					res.push_back(c);
				}
			}
			
			i++;
		}
		else
		{
			if(flag == 1)
			{
				h = v2[j].y;
				Coordinate d(v2[j].x, h);
				res.push_back(d);
			}
			else
			{
				if(v2[j].y > h)
				{
					h = v2[j].y;
					flag = 1;
					Coordinate d(v2[j].x, h);
					res.push_back(d);
				}

			}
			
			j++;
		}
	}

	while(i < v1.size())
	{
		Coordinate e(v1[i].x, v1[i].y);
		res.push_back(e);
		i++;
	}

	while(j < v2.size())
	{
		Coordinate f(v2[j].x, v2[j].y);
		res.push_back(f);
		j++;
	}

	return res;
}

vector<Coordinate> solve(vector<Rec>& B, int start, int end)
{
	int n = end - start + 1;
	if(n == 1)
	{
		vector<Coordinate> res;
		Coordinate a(B[start].a, B[start].h);
		Coordinate b(B[start].b, 0);
		res.push_back(a);
		res.push_back(b);
		return res;
	}

	int mid = (start + end) / 2;
	vector<Coordinate> v1 = solve(B, start, mid);
	vector<Coordinate> v2 = solve(B, mid+1, end);
	vector<Coordinate> v = merge(v1, v2);

	printCoordinate(v1);
	printCoordinate(v2);
	printCoordinate(v);
	cout << endl;

	return v;
}

int main()
{
	// vector<int> nums1{1, 5, 11};
	// vector<Rec> v1 = genBuilding(nums1);
	// printRec(v1);
	// printCoordinate(solve(v1, 0, v1.size() - 1));

	vector<int> nums2{1,5,11, 2,7,6, 3,9,13, 12,16,7, 14,25,3, 19,22,18, 23,29,13, 24,28,4};
	vector<Rec> v2 = genBuilding(nums2);
	printRec(v2);
	printCoordinate(solve(v2, 0, v2.size() - 1));

}