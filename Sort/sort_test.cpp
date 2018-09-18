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
	cout << endl;

	cout << "binary insert sort:" << endl;
	a = genRandomArray();
	printArray(a);
	binaryInsertSort(a);
	printArray(a);
	cout << endl;

	cout << "select sort:" << endl;
	a = genRandomArray();
	printArray(a);
	selectSort(a);
	printArray(a);
	cout << endl;

	cout << "heap sort:" << endl;
	a = genRandomArray();
	printArray(a);
	heapSort(a);
	printArray(a);
	cout << endl;

	cout << "bubble sort:" << endl;
	a = genRandomArray();
	printArray(a);
	bubbleSort(a);
	printArray(a);
	cout << endl;

	cout << "quick sort:" << endl;
	a = genRandomArray();
	printArray(a);
	quickSort(a);
	printArray(a);
	cout << endl;

	cout << "merge sort:" << endl;
	a = genRandomArray();
	printArray(a);
	mergeSort(a);
	printArray(a);
	cout << endl;
}