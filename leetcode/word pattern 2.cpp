//word pattern 2



#include<bits/stdc++.h>

using namespace std;

class TreeNode
{
 public:
	  int val;
	  TreeNode *left,*right;

 TreeNode(int value) : val(value),left(nullptr),right(nullptr){}
};


//Backtracking Approach
class Solution{
public:
	   Solution(){}
	   
	   
	   bool helper(string pattern,string s,int pi,int si,unordered_map<char,string> &uMap)
	   {
	   		for(auto i:uMap)
	   			cout<<i.first<<" "<<i.second<<endl;
	   		cout<<endl;
	   		if(pi==pattern.size() && si==s.size())
	   			return true;
	   		if(pi>=pattern.size() || si>=s.size())
	   			return false;
	   			
	   		if(uMap.find(pattern[pi])!=uMap.end())
	   		{
	   			string curr=uMap[pattern[pi]];
				int length=curr.length();
				if(si+length<=s.size() && curr==s.substr(si,length))
					return helper(pattern,s,pi+1,si+length,uMap);
				return false;
			}
			
			for(auto i=si;i<s.size();i++)
			{
				string curr=s.substr(si,i-si+1);
				
				uMap[pattern[pi]]=curr;
				if(helper(pattern,s,pi+1,i+1,uMap))
					return true;
				uMap.erase(pattern[pi]);
			}
			return false;
	   }
	   
	   //function prototype here
	   bool wordpattern(string pattern,string s)
	   {
	   		if(pattern.size()>s.size())
	   	 		return false;
	   	 	unordered_map<char,string> uMap;
	   	 	return helper(pattern,s,0,0,uMap);
	   }
};

int main()
{
	 Solution s;
	 clock_t t;
	 t=clock();
	 //cout<<s.wordpattern("abab","redblueredblue");
	 //cout<<s.wordpattern("aaaa","asdasdasdasd");
	 cout<<s.wordpattern("aabb","xyzabcxzyabc");
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

