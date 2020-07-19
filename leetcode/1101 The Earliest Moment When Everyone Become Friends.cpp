#include<bits/stdc++.h>

using namespace std;

class TreeNode
{
 public:
	  int val;
	  TreeNode *left,*right;

 TreeNode(int value) : val(value),left(nullptr),right(nullptr){}
};


//union find approach
class Solution {
public:
	//assuming the timestamp are in sorted order already
    int earliestAcq(vector<vector<int>>& logs, int N) {
    	int c=0;
    	vector<int> ranks(N,1);
    	vector<int> parent;
    	for(int current=0;current<N;current++)
    		parent.push_back(current);
    		
    	for(auto log:logs)
    	{
    		int parentu=find(log[1],parent);
    		int parentv=find(log[2],parent);
    		if(parentu!=parentv)
    			UNION(parentu,parentv,parent,ranks),c++;
    			
    		if(c==N-1)
    			return log[0];
		}
		return -1;
    }
    
    void UNION(int u,int v,vector<int> &parent,vector<int> &ranks)
    {
    	if(ranks[u]<ranks[v])
    		parent[u]=v;
    	else if(ranks[u]>ranks[v])
    		parent[v]=u;
    	else
    	{
    		parent[v]=u;
    		ranks[u]++;
		}
	}
    
    int find(int u,vector<int> &parent)
    {
    	return u==parent[u]?u:parent[u]=find(parent[u],parent);
	}
};

int main()
{
	 Solution s;
	 vector<vector<int>> logs{{20190101,0,1},
	 {20190104,3,4},{20190107,2,3},
	 {20190211,1,5},{20190224,2,4},{20190301,0,3},{20190312,1,2},{20190322,4,5}};
	 clock_t t;
	 t=clock();
	 cout<<s.earliestAcq(logs,6);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

