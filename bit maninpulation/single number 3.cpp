/*finding the xor of all element and from the "result"
find the  diffrent bits of first number and last number 
from the "result". And then find the numbers by doing 
and opertion with the numbers. */


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int result=0;
        for(auto &i:nums){result=result^i;}
        int first = 0, second = 0;
        //last diffrent bit of two numbers
        int lsb = ( result & ( result-1 ) ) ^ result; 
        for(auto &i:nums)
        {
            if ( lsb & i )
                first = first ^ i;
            else
                second = second ^ i;
        }
        return {first,second};
    }
};
