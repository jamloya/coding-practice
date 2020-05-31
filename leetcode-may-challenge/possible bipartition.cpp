#include<bits/stdc++.h>

using namespace std;

#define blue 1
#define red 2
#define white 0


class Solution {
public:
    
  
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> track;
        
        for(auto &i :dislikes)
        {    
            track[i[0]].push_back(i[1]);
            track[i[1]].push_back(i[0]);
        }
        
        vector<int> color(N+1,white);
        vector<bool> visit(N+1,false);
        for(int i=1;i<=N;i++)
        {
            if(!visit[i])
            {
                color[i]=blue;
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int curr=q.front();q.pop();

                        if(visit[curr])
                        {
                            continue;
                        }
                    visit[curr]=true;
                    for(auto j:track[curr])
                    {
                        if(color[j]==color[curr])
                            return false;
                        color[j]=color[curr]==red?blue:red;
                        q.push(j);
                    }
                }
            }
        }
        return true;
    }
};
int main()
{
 Solution s;
 cout<<s.();
}

