/* using 3^2=9
and then taking log both side */

class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3),1)==0;
    }
};
