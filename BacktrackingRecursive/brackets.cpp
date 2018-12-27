#include<iostream>
#include<vector>
#include<string>

using namespace std;

void solve(string str, int leftNum, int rightNum)
{
	if(leftNum == 0 && rightNum == 0)
	{
		cout << str << endl;
	}
	
	if(rightNum > leftNum)
	{
		solve(str + ")", leftNum, rightNum - 1);
	}

	if(leftNum > 0)
	{
		solve(str + "(", leftNum - 1, rightNum);
	}
}

int main()
{
	solve("", 3, 3);
}