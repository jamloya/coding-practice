// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    long fun(long start,long end)
    {
        //cout<<start<<end<<endl;
        long mid=(start+end)/2;
        if(start>end)
        {
            return -1;
        }
        
        if(isBadVersion(mid))
        {
            long temp=fun(start,mid-1);
            return temp==-1?isBadVersion(mid)?mid:-1:temp;
           
        }
        else
        {
             long temp=fun(mid+1,end);
            return temp==-1?isBadVersion(mid)?mid:-1:temp;

        }
    }
    
    int firstBadVersion(int n) {
        return fun(1,n);
    }
};
