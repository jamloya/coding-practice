
//1085 sum of digits of minimal number


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
	   
	   int sumOfDigits(int number)
	   {
	   		return  number==0?0:number%10+sumOfDigits(number/10);
	   }
	   //Linear Approach 
	   //O(n)
	   //we can also go with sorting first options
	   //function prototype here
	   int minimalSumOfDigits(vector<int> &nums)
	   {
	   		if(nums.empty())
	   			return -1;
	   		int minimumNumber=INT_MAX;
	   		for(int currentIndex=0;currentIndex<nums.size();currentIndex++)
	   			minimumNumber=min(minimumNumber,nums[currentIndex]);
	   		return sumOfDigits(minimumNumber)%2?0:1;
	   }
};

int main()
{
	 Solution s;
	 vector<int> nums{99,77,33,66,55};
	 clock_t t;
	 t=clock();
	 cout<<s.minimalSumOfDigits(nums);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

