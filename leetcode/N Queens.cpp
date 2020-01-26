class Solution {
public:
    
    int count=0;
    bool issafe(int i,int j)
    {
        if(row[i] || col[j] || uphill[i+j] || downhill[i-j+maxQueens-1]) return false;
        return true;
    }
    
    /*void printboard(int n)
    {
        for(int i=0;i<n;i++)
        {   for(int j=0;j<n;j++)
                cout<<boards[i][j]<<" ";
            cout<<endl;
        }
    }*/
    vector<vector<string>> res;
    
    /*void addtoresult(vector<vector<string>> board)
    {
        vector<string> temp;string a="";
        for(int i=0;i<maxQueens;i++)
        {
            for(int j=0;j<maxQueens;j++)
                a+=board[i][j];
            temp.push_back(a);
            a="";
        }
        res.push_back(temp);
    }*/
    void placeQueen(int currCol)
    {
        
        if(currCol==maxQueens)res.push_back(boards);
        
        for(int i=0;i<maxQueens;i++)
        {
            if(issafe(i,currCol))
            {
                boards[i][currCol]='Q';
                row[i]=col[currCol]=uphill[i+currCol]=downhill[i-currCol+maxQueens-1]=1;
                placeQueen(currCol+1);
                row[i]=col[currCol]=uphill[i+currCol]=downhill[i-currCol+maxQueens-1]=0;
                boards[i][currCol]='.';
            }
        }
     }
    
    
    vector<vector<string>> solveNQueens(int n) {
     
        if (n==0)return {{}};
        if (n==1)return {{"Q"}};
        maxQueens=n;
        boards=vector<string>(n,string(n,'.'));
        row=vector<int> (n,0);
        col=vector<int> (n,0);
        uphill=vector<int> (n*2-1,0);
        downhill=vector<int> (n*2-1,0);
        
        placeQueen(0);
        return res;
    }
    
        
    private:
     int maxQueens;
    vector<string> boards;
    vector<int> row;
    vector<int> col;
    vector<int> uphill;
    vector<int> downhill;



};
