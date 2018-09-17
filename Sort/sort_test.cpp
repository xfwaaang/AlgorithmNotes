/*
the test code of sort
*/

#include<iostream>
#include"../util.h"
#include"sort.h"

using namespace std;

int main()
{
	vector<int> a;

	cout << "insert sort:" << endl;
	a = genRandomArray();
	printArray(a);
	insertSort(a);
	printArray(a);

	cout << "binary insert sort:" << endl;
	a = genRandomArray();
	printArray(a);
	binaryInsertSort(a);
	printArray(a);

	cout << "quick sort:" << endl;
	a = genRandomArray();
	printArray(a);
	quickSort(a);
	printArray(a);
}