#include<iostream>
#include<unordered_map>
#include<vector>
#include<typeinfo>
#include<queue>


using namespace std;

int orangesRotting(vector<vector<int>>& grid) 
{
        int n = grid.size();
        int m = grid[0].size();
        
        int res = -1;
        queue<pair<int,int> > help;
        
        help.push(make_pair(0, 0));

        while(!help.isEmpty())
        {
        	auto e = help.top();
        	help.pop();
        	
        }
        
       
        return res;
        
    
}

int main()
{
	
}