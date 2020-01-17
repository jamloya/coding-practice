
class Solution {
    private:
    void backtrack(vector<int> &nums,int i,vector<int> &tempres,vector<vector<int>> &result)
    {
        result.push_back(tempres);
        for(int j=i;j<nums.size();j++)
        {
            tempres.push_back(nums[j]);
            backtrack(nums,j+1,tempres,result);
            tempres.pop_back();
        }
        
    }
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tempres;
        backtrack(nums,0,tempres,result);
        return result;
    }
};
