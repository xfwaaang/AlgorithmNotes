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
