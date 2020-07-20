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
	   void segregate(vector<int> &nums)
	   {
	   		if(nums.empty())
	   			return ;
	   		int left=0,right=nums.size()-1;
	   		
	   		while(left<right)
	   		{
	   			while(nums[left]!=1)
				   left++;
				while(nums[right]!=0)
					right--;
				
				if(left>right)
					break;
				swap(nums[left],nums[right]);	
			}
	   }
};

int main()
{
	 Solution s;
	 vector<int> nums { 0, 1, 0, 1, 1, 1 };
	 clock_t t;
	 t=clock();
	 s.segregate(nums);
	 for(auto i:nums)
	 	cout<<i<<" ";
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

