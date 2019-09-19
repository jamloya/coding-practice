class Solution {
public:
    int binary_search(vector<int> nums,int left,int right,int target)
    {
        if (left>right) return -1;
        int mid=(left+right)/2;
        if (nums[mid]==target) return mid;
        else if(nums[mid]<target) return binary_search(nums,mid+1,right,target);
        else return binary_search(nums,left,mid-1,target);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size()==0){return res={-1,-1};}
        if(nums.size()==1){return nums[0]==target?res={0,0}:res={-1,-1}; }
        int binaryResult=binary_search(nums,0,nums.size()-1,target);
        if(binaryResult==-1)
        {
            return res={-1,-1};
        }
        else
        {
            int start=binaryResult;
            int last=start;
            while(true)
            {    //cout<<last<<start<<endl;
                if(last+1<=nums.size()-1 && nums[start]==nums[last+1] ){last++;}
                else {break;}
            }
            while(true)
            {//cout<<start<<endl;
                if((start-1)>=0 && nums[start-1]==nums[start] ){start--;}
                else {break;}
            }
            return res={start,last};
        }
    }
};
