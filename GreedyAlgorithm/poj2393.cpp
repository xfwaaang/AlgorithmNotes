#include<iostream>

using namespace std;

int main()
{
	int n, s;
	while(cin >> n >> s)
	{
		int c[n], y[n];

		for(int i=0; i<n; ++i)
			cin >> c[i] >> y[i];

		long long res = 0;
		int minc = 5000 + 100;

		for(int i=0; i<n; ++i)
		{
			minc = min(minc, c[i]);
			res += minc * y[i];
			minc += s;
		}

		cout << res << endl;;
	}
}