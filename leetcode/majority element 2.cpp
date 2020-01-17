/*using two candidates for two max frequency numbers*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int max1=INT_MIN,max2=INT_MIN,count1=0,count2=0;
        for(auto &i : nums)
        {
            if (max1 == i)count1++;
            else if(max2 == i)count2++;
            else if(count1 == 0)
                {  
                    max1=i; 
                    count1++;
                }
            else if(count2 == 0)
                {
                    max2=i;
                    count2++;
                }
            else
                {
                    count1--;
                    count2--;
                }
        }
        count1=0;
        count2=0;
        for(auto &i : nums)
        {
            if(max1 == i)count1++;
            else if(max2 == i)count2++;
        }
        vector<int> result;
        if(count1>nums.size()/3)result.push_back(max1);
        if(count2>nums.size()/3)result.push_back(max2);
        return result;
    }
};
