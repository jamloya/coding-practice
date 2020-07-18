#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
	   Solution(){}
	   
	   //function prototype here
	   
	   vector<int> rangeAddition(vector<vector<int>> &queries,int length)
	   {
	   		vector<int> result(length,0);
	   		for(auto currentQuery:queries)
	   		{
				result[currentQuery[0]]+=currentQuery[2];
				if(currentQuery[1]+1!=length)
					result[currentQuery[1]+1]-=currentQuery[2];
		    }
		    
		    for(auto i(1);i<length;i++)
		    	result[i]+=result[i-1];
		    	
		    return result;
	   			
	   }
};

int main()
{
	 Solution s;
	 vector<vector<int>> queries{{1,  3,  2},{2,  4,  3},{0,  2, -2}};
	 int length=5;
	 clock_t t;
	 t=clock();
	 for(auto i:s.rangeAddition(queries,length))
	 	cout<<i<<" ";
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

