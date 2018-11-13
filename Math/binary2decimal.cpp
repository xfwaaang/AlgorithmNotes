#include<iostream>

using namespace std;

int solve(int a)
{
	int res = 0;
	int t = 1;

	while(a)
	{
		res += t * a % 10;
		a /= 10;
		t *= 2;
	}

	return res;
}

int main()
{
	int a;
	while(cin >> a)
		cout << "binary: " << a << endl << "decimal: " <<  solve(a) << endl;
}