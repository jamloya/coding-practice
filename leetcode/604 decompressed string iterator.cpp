#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
	   Solution(string s){
	   	for(auto ch:s)
	   		if(isdigit(ch))
	   			frequency.push_back(ch-'0'); // if given theres double digits change this.
	   		else
	   			currentChar.push_back(ch);
	   	 totalCharacter=frequency.size();
	   	 currentIndex=0;
	   }
	   
	   
	   //assuming calling next when iterator is at last it will return '-';
	   char next()
	   {
	   		if(this->hasNext()==false)
	   			return '-';
	   		char nextCharacter=currentChar[currentIndex];
	   		if(--frequency[currentIndex]==0)
	   			currentIndex++;
	   		return nextCharacter;
	   }
	   
	   bool hasNext(){
	   		return currentIndex!=totalCharacter;
	   }
	   
	  
private:
	vector<int> frequency; //stores the frequency of each character
	vector<char> currentChar; // stores the character
	int currentIndex,totalCharacter;
	
};

int main()
{
	 Solution iterator("L1e2t1C1o1d1e1");
	 clock_t t;
	 t=clock();
	 cout<<iterator.next()<<endl; // return 'L'
	 cout<<iterator.next()<<endl; // return 'e'
	 cout<<iterator.next()<<endl; // return 'e'
	 cout<<iterator.next()<<endl; // return 't'
	 cout<<iterator.next()<<endl; // return 'C'
	 cout<<iterator.next()<<endl; // return 'o'
	 cout<<iterator.next()<<endl; // return 'd'
	 cout<<iterator.hasNext()<<endl; // return true
	 cout<<iterator.next()<<endl; // return 'e'
	 cout<<iterator.hasNext()<<endl; // return false
	 cout<<iterator.next()<<endl; // return ' '
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

