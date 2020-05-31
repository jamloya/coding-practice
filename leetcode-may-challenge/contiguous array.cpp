#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> keepIndex;
        keepIndex[0]=0;
        int count=0,result=0;
        
        for(int i=0;i<nums.size();i++)
        {
            count+=nums[i]==0?1:-1;
            if(keepIndex.find(count)!=keepIndex.end())
                result=max(result,i-keepIndex[count]+1);
            else
                keepIndex[count]=i+1;
        }
        return result;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

