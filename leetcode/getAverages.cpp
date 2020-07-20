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
	   
	   vector<pair<int,double>> getAverage(vector<vector<int>> marks)
	   {
			if(marks.empty())
				return {};
			vector<pair<int,double>> averages;
			unordered_map<int,priority_queue<int,vector<int>,greater<int>>> top5marks;
			for(auto currentRecord:marks)
			{
				top5marks[currentRecord[0]].push(currentRecord[1]);
				if(top5marks[currentRecord[0]].size()>5)
					top5marks[currentRecord[0]].pop();
			}
			for(auto i:top5marks)
			{
				int totalMarks=0;
				while(!i.second.empty())
					totalMarks+=i.second.top(),i.second.pop();
				averages.push_back({ i.first ,(double)totalMarks/5 });
			}
			return averages;
	   }
};

int main()
{
	 Solution s;
	 vector<vector<int>> marks {{1,91},{1,92},{2,93},{2,97},{1,60},{2,77},{1,65},{1,87},{1,100},{2,100},{2,76}} ;
	 clock_t t;
	 t=clock();
	 for(auto i:s.getAverage(marks) )
	 	cout<<i.first<<" "<<i.second<<endl;
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

