#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum=*max_element(candies.begin(),candies.end());
        vector<bool> result;
		for (auto i:candies)
        	result.push_back((i+extraCandies)>=maximum);
        return result;
    }
};

int main()
{
 Solution s;
 vector<int> candies{2,3,5,1,3};
 s.kidsWithCandies(candies,3);
}

