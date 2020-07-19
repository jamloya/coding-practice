#include<bits/stdc++.h>

using namespace std;

class TreeNode
{
 public:
	  int val;
	  TreeNode *left,*right;

 TreeNode(int value) : val(value),left(nullptr),right(nullptr){}
};




class Logger{
public:
	   Logger(){}
	   
	   //function prototype here
		bool shouldPrintMessage(int timestamp,string message)
		{
			if(timers.find(message)!=timers.end())
				if(timestamp-timers[message]>=10)
				{
					timers[message]=timestamp;
					return true;
				}
				else
					return false;
			timers[message]=timestamp;
			return true;	
		}	   
private:
	unordered_map<string,int> timers;
};

int main()
{
	 
	 clock_t t;
	 t=clock();
	 Logger logger;
	
	// logging string "foo" at timestamp 1
	cout<<logger.shouldPrintMessage(1, "foo"); //returns true; 
	
	// logging string "bar" at timestamp 2
	cout<<endl<<logger.shouldPrintMessage(2,"bar"); //returns true;
	
	// logging string "foo" at timestamp 3
	cout<<endl<<logger.shouldPrintMessage(3,"foo"); //returns false;
	
	// logging string "bar" at timestamp 8
	cout<<endl<<logger.shouldPrintMessage(8,"bar"); //returns false;
	
	// logging string "foo" at timestamp 10
	cout<<endl<<logger.shouldPrintMessage(10,"foo"); //returns false;
	
	// logging string "foo" at timestamp 11
	cout<<endl<<logger.shouldPrintMessage(11,"foo"); //returns true;
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}




