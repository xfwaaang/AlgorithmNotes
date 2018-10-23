/*
poj1050
求具有最大和的子矩阵
*/

#include<iostream>

using namespace std;

int m[101][101];

int main()
{
	int n, max, i, j, k, tmp;

	while(cin >> n)
	{
		max = -10000;

		// 输入每行元素时，求出每行的最大子数组和
		for(i=0; i<n; ++i)
		{
			tmp = 0;
			for(j=0; j<n; ++j)
			{
				cin >> m[i][j];
				if(tmp > 0)	
					tmp += m[i][j];
				else 
					tmp = m[i][j];

				if(tmp > max)	
					max = tmp;
			}
		}

		// 将 i+1 行至 n-1 行对应列的元素依次加到 i 行
		// 每加一行，就求一次当前叠加行的最大子数组和
		for(i=0; i<n-1; ++i)
		{
			for(j=i+1; j<n; ++j)
			{
				tmp = 0;
				for(k=0; k<n; ++k)
				{
					m[i][k] += m[j][k];
					if(tmp > 0)
						tmp += m[i][k];
					else
						tmp = m[i][k]; 

					if(tmp > max)	
						max = tmp;
				}
			}
		}

		cout << max << endl;
	}

}
