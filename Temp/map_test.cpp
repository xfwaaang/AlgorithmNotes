#include<iostream>
#include<unordered_map>
#include<vector>
#include<typeinfo>

using namespace std;

int main()
{
	unordered_map<int, int> help;
	vector<int> a{1, 2, 3, 3};
	for(auto e : a)
		help[e]++;
	for(auto e : help)
		cout << e.second << endl;
}