class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row=0,col=-1;
        vector<vector<int>> res(r,vector(c,0));
        for(int i=0;i<nums.size();i++)
        { 
            for(int j=0;j<nums[i].size();j++)
            {   col++;
                if (col==c){col=0;row++;}
                res[row][col]=nums[i][j];
            }
        }
        cout<<col<<row<<endl;
        if(row+1!=r || col+1!=c){return nums;}
        return res;
    }
};
