#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

 bool isPrime(int k)
    {
        if(k < 2)
            return false;

        for(int i=2; i<=k/2; ++i)
        {
            if(k % i == 0)  return false; 
        }
        
        return true;
    }
    
    int countPrimeSetBits(int L, int R) {
        int count = 0;
        int i = 0;
        int tmp = 0;

        for(int k = L; k<=R; ++k)
        {
            i = 0;
            tmp = k;
            while(tmp)
            {
                i += tmp % 2;
                tmp >>= 1;
            }
            
            if(isPrime(i))  count++;
        }
        
        return count;
    }
int main()
{
    cout << countPrimeSetBits(842, 888) << endl;
    for(int i=0; i<=100; ++i)
    {
        if(isPrime(i))
            cout << i << " ";
    }
}