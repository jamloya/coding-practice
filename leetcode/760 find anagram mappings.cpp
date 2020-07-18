#include<bits/stdc++.h>

using namespace std;

class Solution{
	
	public:
	vector<int> findanagram(vector<int> &A,vector<int> &B)
	{
		unordered_map<int,vector<int>> uMap;
		for(auto i(0);i<B.size();i++)
			uMap[B[i]].push_back(i);
			
		vector<int> mappings;
		for(int i=0;i<A.size();i++)
		{
			mappings.push_back(uMap[A[i]].back());	
			uMap[A[i]].pop_back();
		}
		return mappings;
	}
};

int main()
{
 Solution s;
 
 vector<int> A{12,28,46,32,50};
 vector<int> B{50,12,32,46,28};
 
  	clock_t t; 
  	t = clock();  
 	for(auto i:s.findanagram(A,B))
		cout<<i<<" ";
	t = clock() - t; 
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	cout<<endl<<to_string(time_taken);
return 0;
}

