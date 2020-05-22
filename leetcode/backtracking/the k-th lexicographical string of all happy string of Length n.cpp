#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
	
	void fun(vector<char> &characters,int &n,int &k,string &current,vector<string> &result)
	{
		if(result.size()==k)
			return;
		if(current.size()==n)
        {
            result.push_back(current);
            return;
        }
			
		for(int i=0;i<characters.size();i++)
			if(current.size()==0 || current.back()!=characters[i])
			{
				current+=characters[i];
				fun(characters,n,k,current,result);
		  		current.pop_back();
			}
		
	}
	
    string getHappyString(int n, int k) {
  		vector<char> characters{'a','b','c'};
  		vector<string> ans;
  		if(k> 3 * pow(2, 1 <<(n-1)))
  	    	return "";
		  
		  string current="";
		  fun(characters,n,k,current,ans);
		  
		  if(ans.size()==k)
		  	return ans.back();
		return "";
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

