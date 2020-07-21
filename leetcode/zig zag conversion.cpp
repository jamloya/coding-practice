/*
	The converted array should be in form a < b > c < d > e < f.
*/


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
		void convertZigZag(vector<int> &nums)
		{
			if(nums.empty() || nums.size()<2)
				return;
				
			bool flag=1;
			if(nums[0]>nums[1])
				swap(nums[0],nums[1]);
			for(int i=1;i<nums.size()-1;i++)
			{
				if(flag)
					{
						if(nums[i]<nums[i+1])
							swap(nums[i],nums[i+1]);
					}
				else
					if(nums[i]>nums[i+1])
						swap(nums[i],nums[i+1]);
				flag=!flag;
			}
		}
};
int main()
{
	 Solution s;
	 vector<int> nums{4, 3, 7, 8, 6, 2, 1};
	 clock_t t;
	 t=clock();
	 s.convertZigZag(nums);
	 for(auto i:nums)
	 	cout<<i<<" ";
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

