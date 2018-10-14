#### 题目描述
给定两个序列X和Y，求它们的最长公共子序列(longest common subsequence)

#### 解题思路
设X[m]=(x1,x2,...,xm)和Y[n]=(y1,y2,...,yn)，Z=(z1,z2,...,zk)是X和Y的最长公共子序列，则

1. 若xm = yn，则zk=xm=yn，且Z[k-1]是X[m-1]和Y[n-1]的最长公共子序列
2. 若xm！= yn且zk！= xm，则Z是X[m-1]和Y的最长公共子序列
3. 若xm！= yn且zk！= yn，则Z是X和Y[n-1]的最长公共子序列

我们需要一个二维数组来保存最长公共子序列的长度，设c[i][j]保存X[i]=(x1,x2,...,xi)和Y[j]=(y1,y2,...,yj)的最长子序列的长度

```
	       0                           i=0 or j=0      
c[i][j] =  c[i-1][j-1] + 1             i,j>0, xi = yj
           max(c[i-1][j], c[i][j-1])   i,j>0, xi != yj
```

还需要数组s[m][n]来记录状态，s[i][j]=1,2,3 , 最终用来构造最长公共子序列

#### 代码实现

[code](/DynamicPrograming/lcs.cpp)

```
class LCS
{
public:
	LCS(int nx, int ny, string x, string y);
	void LCSLength();
	void CLCS();

private:
	void CLCS(int i, int j);
	int **c, **s, m, n;
	string lcs;
};

int LCS::LCSLength()
{
	for(int i=1; i<=m; i++)	c[i][0] = 0;
	for(int i=1; i<=n; i++) c[0][i] = 0;

	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(x[i] == y[j])
			{
				c[i][j] = c[i-1][j-1] + 1;
				s[i][j] = 1;
			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				s[i][j] = 2;	
			}
			else
			{
				c[i][j] = c[i][j-1];
				s[i][j] = 3;
			}
		}
	}

	return c[m][n];
}

void LCS::CLCS(int i, int j)
{
	if(i == 0 || j == 0)	return;
	if(s[i][j] == 1)
	{
		CLCS(i-1, j-1);
		lcs += x[i];
	}
	else if(s[i][j] == 2)
		CLCS(i-1, j);
	else
		CLCS(i, j-1);
}

```