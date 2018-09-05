/*
转换为小写
如：
Hello - hello
love&OK - love&ok
LONEly - lonely
*/

#include<iostream>
#include<string>

using namespace std;

string toLowCase(string str)
{
	for(int i=0; i<str.size(); ++i)
	{
		if(str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
	}
	return str;
}

// string toLowCase(string str)
// {
// 	for(char& c : str)
// 		if(c >= 'A' && c <= 'Z')	c += 32;
// 	return str;
// }


int main()
{
	cout << "转换为小写单词" << endl;
	string str1 = "Hello";
	string str2 = "love&OK";
	string str3 = "LONEly";
	cout << str1 << " -> " << toLowCase(str1) << endl;
	cout << str2 << " -> " << toLowCase(str2) << endl;
	cout << str3 << " -> " << toLowCase(str3) << endl;

}
