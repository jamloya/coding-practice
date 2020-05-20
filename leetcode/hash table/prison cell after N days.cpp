#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    //Brute Force O(N)
    vector<int> prisonAfterNDays1(vector<int>& cells, int N) {
        for(int i=0;i<N;i++)
        {
            vector<int> newCell(8,0);
            for(int i=1;i<7;i++)
                newCell[i]=cells[i+1]==cells[i-1]?1:0;
            cells=newCell;
        }
        return cells;
    }
    
    
    //the sequence repeats itslef after every 14th day;
    //so we can skip the loop i+=14
    //O(N%14)
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        N=N%14;
        if(N==0)N=14;
        for(int i=0;i<N;i++)
        {
            vector<int> newCell(8,0);
            for(int i=1;i<7;i++)
                newCell[i]=cells[i+1]==cells[i-1]?1:0;
            cells=newCell;
        }   
        return cells;
    }
    
    
};
int main()
{
 Solution s;
 cout<<s.();
}

