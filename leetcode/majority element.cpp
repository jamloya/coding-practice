//boyer mooore voting algorithm ( only for two distinct elements )


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int result;
        for(auto &i:nums)
        {
            if ( count==0 )
                result=i;
            count+= result == i ? 1 : -1;
        }
        return result;
    }
};
