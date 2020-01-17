class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twos=0;
        for(auto i:nums)
        {
            /* if number is appear one or when it appears for third time 
            remove it from twos */
            ones=(ones^i) & ~twos; 
            /*if number appear twice add it to twos
            and remove from ones*/
            twos=(twos^i) & ~ones;
        }
        return ones;
    }
};
