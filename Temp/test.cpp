#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> v(10);
    bool canWinNim(int n, int count = 0) {
        if(n <= 3)
        {
            if(count % 2 == 1)
                return false;
            else
                return true;
        }
        return canWinNim(n-1, count+1) || canWinNim(n-2, count+1) || canWinNim(n-3, count+1);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    vector<int> v(10, 1);
    return 0;
}