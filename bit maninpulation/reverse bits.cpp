class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int temp=0;
        for(int i=0;i<32;i++)
        {
            temp=temp<<1;
            if(n & 1 == 1 )
            {
                temp=temp^1;
            }
            n=n>>1;
            
        }
        return temp;
    }
};
