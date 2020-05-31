#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> numbers;
        for(int i=1;i<10;i++)
            numbers.push(i);
        vector<int> finalResult;
        while(!numbers.empty())
        {
            int current=numbers.front();
            numbers.pop();
            if(current<=high && current>=low)
                finalResult.push_back(current);
            if (current>high)
                break;
            int rem=current%10;
            if(rem<9)
                numbers.push(current*10+(rem+1));
        }
        return finalResult;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

