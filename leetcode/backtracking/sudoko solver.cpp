class Solution {
public:
    
    bool isSafe(int i,int j,char num)
    {
        
        if(rowCheck[i][num-'0'] || colCheck[j][num-'0']  )return false;
        i = i - i%3; j = j - j%3;
        for(int x = i; x<i+3;x++)
        {
            for(int y = j; y < j+3 ;y++)
                if(result[x][y]==num)return false;
        }
        return true;
    }
    
    void printRow(int i)
    {
        for(int j=0;j<9;j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
    bool backtrack(int currRow,int currCol)
    {
        //printRow(currRow);
        if ( currRow == maxSize) return true;
        if(currCol==maxSize)
            return backtrack(currRow+1,0);
        if(result[currRow][currCol]!='.')
            return backtrack(currRow,currCol+1);
        
        for(char ch='1';ch<='9';ch++)
        {
            if( isSafe(currRow,currCol,ch) )
            {
                result[currRow][currCol]=ch;
                int temp=ch-'0';
                rowCheck[currRow][temp]=true;
                colCheck[currCol][temp]=true;
                if ( backtrack(currRow,currCol+1) ) return true;
                result[currRow][currCol]='.';
                rowCheck[currRow][temp]=false;
                colCheck[currCol][temp]=false;
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        
        maxSize=board.size();
        //cout<<maxSize;
        rowCheck=vector(maxSize,vector<bool>(maxSize+1,false));
        colCheck=vector(maxSize,vector<bool>(maxSize+1,false));
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='.')continue;
                int k=board[i][j]-'0';
                rowCheck[i][k]=true;
                colCheck[j][k]=true;
            }
        }
        
        result=board;
        cout<<backtrack(0,0);
        board=result;
    }
    
    private:
    
    int maxSize;
    vector<vector<char>> result;
    vector<vector<bool>> rowCheck;
    vector<vector<bool>> colCheck;
};
