#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
	   Solution(int size){
	   	this->size=size;
	   	this->sum=0;
	   }
	   
	   //function prototype here
	   double movingAverage(int num)
	   {
	   		sum+=num;
	   		currentNumber.push(num);
	   		if(currentNumber.size()>this->size)
	   			sum-=currentNumber.front(),currentNumber.pop();
	   			
	   		return (double)sum/currentNumber.size();
	   }
	   
private:
	int sum;
	queue<int> currentNumber;
	int size;
};

int main()
{
	 Solution s(3);
	 clock_t t;
	 t=clock();
	 cout<<s.movingAverage(1)<<endl;
	 cout<<s.movingAverage(10)<<endl;
	 cout<<s.movingAverage(3)<<endl;
	 cout<<s.movingAverage(5)<<endl;
	 cout<<s.movingAverage(11)<<endl;
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

