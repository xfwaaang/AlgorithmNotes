#include<iostream>
#include"../util.h"

using namespace std;

vector<int> shortestToChar(string S, char C) {
        vector<int> res;
        
        int n = S.size();
        int c_i = -n;
        int c_j = 0;
        
        while(S[c_j] != C)  ++c_j;
        
        for(int i=0; i<n; ++i)
        {
            if(S[i] == C)
            {
                c_i = i;
                c_j = i + 1;
                while(c_j < n && S[c_j] != C)  ++c_j;
                if(c_j >= n)  c_j = 2 * n;

                cout << i << " " << c_i << " " << c_j << endl;

            }

            cout << i << " " << c_i << " " << c_j << endl;
            
            res.push_back(min(i - c_i, c_j - i));
        }
        
        return res;
    }

int main()
{
    string s = "loveleetcode";
    char c = 'e';

    printArray(shortestToChar(s, c));
}