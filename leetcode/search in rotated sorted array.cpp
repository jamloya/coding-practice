class Solution {
public:
    int findsp(vector<int> nums)
    {
        int left=0;
        int right=nums.size()-1;
        int mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            
            if(mid==nums.size()-1) return 0;
            else if(nums[mid]>nums[mid+1])
            {
                return mid;
            }
            else
            {
                //cout<<nums[mid]<<nums[mid+1]<<endl;
                if(nums[mid]<=nums[nums.size()-1]) 
                {
                    right=mid-1;
                }
                else 
                {  
                    left=mid+1;}
            }
        }
        return left;
    }
    
    int binarysearch(vector<int> nums,int left,int right,int target)
    {
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) if(nums[0] == target) return 0; else return -1;
        int sp,result;
        sp=findsp(nums);
        //cout<<sp;
        if(target>=nums[0] && target <=nums[sp])
        {
            result=binarysearch(nums,0,sp,target);
        }
        else if(target>=nums[sp+1]  && target <=nums[nums.size()-1])
        {
            result=binarysearch(nums,sp+1,nums.size()-1,target);
        }
        else result=-1;
        return result;
    }
    
};
