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
	   
	   
	   //divide and conquer approach 
	   //o(log n)
	   //function prototype here
	   int fixedPoint(vector<int> nums)
	   {
	   		if(nums.empty())
	   			return -1;
	   			
	   		int left=0,right=nums.size();
	   		
	   		while(left<right)
	   		{
	   			int mid=(left+right)/2;
				if(nums[mid]==mid)
					return mid;
					
				else if(nums[mid]>mid)
					right=mid;
				else
					left=mid+1;	
			}
			return -1;
	   }
};

int main()
{
	vector<int> nums{0,2,5,6,7};
	 Solution s;
	 clock_t t;
	 t=clock();
	 cout<<s.fixedPoint(nums);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

