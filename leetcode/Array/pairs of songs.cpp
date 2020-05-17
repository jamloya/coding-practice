#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	/* Brute Force
    int numPairsDivisibleBy60(vector<int>& time) {
  		int result=0;
		for(int i=0;i<time.size()-1;i++)
			for(int j=i+1;j<time.size();j++)
				result+=(time[i]+time[j])%60==0?1:0;
		return result;
    }*/
    
    int numPairsDivisibleBy60(vector<int>& time) {
    	{
    		vector<int> keepTrack(60);
	        int result=0;
	      for (auto t : time) {
	        result += keepTrack[(60 - t % 60) % 60];
	        ++keepTrack[t % 60];
	      }
	      return result;
		}
	}
    
};


int main()
{
 Solution s;
 vector<int> time{20,30,150,100,40};
 cout<<s.numPairsDivisibleBy60(time);
}

