
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


class Solution{
public:
	   Solution(){}
	   
	   //function prototype here
	   
	   vector<int> countFrequencies(vector<int> &nums)
	   {
	   		int i=0;
	   		while(i<nums.size())
	   		{
	   			if(nums[i]<=0)
				{
					i++;
					continue;
				}
				int ei=nums[i]-1;
			   	if(nums[ei]>0)
			   	{
			   		nums[i] = nums[ei];
					nums[ei]=-1;	
				}
				else
				{
					nums[ei]--;
					nums[i]=0;
					i++;
				}
				
			}
			for(auto &i:nums)
				i=abs(i);
				
			return nums;
	   }
};

int main()
{
	 Solution s;
	 vector<int> nums{2,3,2,3,5};
	 clock_t t;
	 t=clock();
	 for(auto i:s.countFrequencies(nums))
	 	cout<<i<<" ";
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

