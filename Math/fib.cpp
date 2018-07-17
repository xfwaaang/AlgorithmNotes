/*
求解斐波那契数列
斐波那契数列：0,1,1,2,3,5,8...
*/

#include <iostream>
using namespace std;

/*
递归
*/
int fib_recursive(int n){
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fib_recursive(n-2) + fib_recursive(n-1); 
}

/*
迭代
*/
int fib_iterative(int n){
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    int num;
    int fib_1 = 0;
    int fib_2 = 1;
    for(int i=2; i<=n; i++){
        num = fib_1 + fib_2;
        fib_1 = fib_2;
        fib_2 = num;
    }

    return num;
}

int main()
{
	for (int i = 0; i < 20; ++i)
	{
		cout << fib_recursive(i) << " ";
	}

	cout << endl;

	for (int i = 0; i < 20; ++i)
	{
		cout << fib_iterative(i) << " ";
	}
}