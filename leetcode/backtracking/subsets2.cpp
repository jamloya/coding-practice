class Solution {
    
    void backtrack(vector<int> &nums,int i,vector<int> &tempres,set<vector<int>> &result)
    {
        result.insert(tempres);
        for(int j=i;j<nums.size();j++)
        {
            tempres.push_back(nums[j]);
            backtrack(nums,j+1,tempres,result);
            tempres.pop_back();
        }
        
    }
    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> result;
        sort(nums.begin(),nums.end());
        vector<int> tempres;
        backtrack(nums,0,tempres,result);
        vector<vector<int>> realresult;
        for(auto it=result.begin();it!=result.end();it++)
        {
            realresult.push_back(*it);
        }
        return realresult;
    }
};
