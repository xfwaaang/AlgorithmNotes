#### 题目描述
给定两个序列X和Y，求它们的最长公共子序列的长度(longest common subsequence)

#### 解题思路
设`X[m]=(x1,x2,...,xm)`和`Y[n]=(y1,y2,...,yn)`，`Z=(z1,z2,...,zk)`是`X`和`Y`的最长公共子序列，则

1. 若`xm = yn`，则`zk=xm=yn`，且`Z[k-1]`是`X[m-1]`和`Y[n-1]`的最长公共子序列
2. 若`xm！= yn`且`zk！= xm`，则`Z`是`X[m-1]`和`Y`的最长公共子序列
3. 若`xm！= yn`且`zk！= yn`，则`Z`是`X`和`Y[n-1]`的最长公共子序列

我们需要一个二维数组来保存最长公共子序列的长度，设`c[i][j]`保存`X[i]=(x1,x2,...,xi)和Y[j]=(y1,y2,...,yj)`的最长子序列的长度

```
	       0                           i=0 or j=0      
c[i][j] =  c[i-1][j-1] + 1             i,j>0, xi = yj
           max(c[i-1][j], c[i][j-1])   i,j>0, xi != yj
```

#### 代码实现

[code](/DynamicPrograming/lcs.cpp)

```cpp
int LCSLength(string x, string y)
{
	int m = x.size();
	int n = y.size();
	int c[m+1][n+1];

	for(int i=0; i<=m; i++)	c[i][0] = 0;
	for(int i=0; i<=n; i++) c[0][i] = 0;

	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(x[i] == y[j])
			{
				c[i][j] = c[i-1][j-1] + 1;
			}
			else
			{
				c[i][j] = max(c[i-1][j], c[i][j-1]);
			}
		}

	}

	return c[m][n];
}
```