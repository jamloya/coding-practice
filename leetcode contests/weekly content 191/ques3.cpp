#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_set<int> change;
        vector<vector<int>> v(n,vector<int>{});
        vector<vector<int>> v1(n,vector<int>{});
        int result=0;
        for(auto i:connections)
        {
            if(i[0]==0)
            {
                result++;
                change.insert(i[1]);
            }
            else if(i[1]==0)
            {
                change.insert(i[0]);
            }
            else
            {
                v[i[0]].push_back(i[1]);
                v1[i[1]].push_back(i[0]);
            }
        }
        for(int i=1;i<n;i++)
        {
            if(change.find(i)!=change.end())
            {
                cout<<i<<endl;;
                for(auto j:v[i])
                {
                    if(change.insert(j).second)
                        result++;
                }
                for(auto j:v1[i])
                    change.insert(j);
            }
        }
        return result;
    }
};


int main()
{
 Solution s;
 cout<<s.();
}

