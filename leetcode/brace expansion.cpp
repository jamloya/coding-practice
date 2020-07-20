#include<bits/stdc++.h>

using namespace std;

class TreeNode
{
 public:
	  int val;
	  TreeNode *left,*right;

 TreeNode(int value) : val(value),left(nullptr),right(nullptr){}
};

class Node
{
 public:
 		int val;
 		Node *next;
 		
  Node(int value) : val(value),next(nullptr) {}
};


class Solution {
public:
    vector<string> expand(string S) {
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='{'||S[i]=='}') 
                S[i]=' ';
        }
        
        vector<vector<string>> v;
        istringstream iss(S);
        string tmp;
        while(getline(iss,tmp,' ')) 
        {
            if(tmp.empty()) continue;
            vector<string> options;
            istringstream subiss(tmp);
            string subtmp;
            while(getline(subiss,subtmp,',')) 
                options.push_back(subtmp); 
            v.push_back(options);
        }
 		
        vector<string> result;
        DFS(v,0,"",result);
        sort(result.begin(),result.end());
        return result;
    }
    
    void DFS(vector<vector<string>>& v, int i, string cur, vector<string>& result)
    {
        if(i==v.size())
        {
            result.push_back(cur);
            return;
        }
        for(string option:v[i]) DFS(v,i+1,cur+option,result);
    }
};

int main()
{
	 Solution s;
	 clock_t t;
	 t=clock();
	 for(auto i:s.expand("{a,b}c{d,e}f"))
	 	cout<<i<<endl;
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

