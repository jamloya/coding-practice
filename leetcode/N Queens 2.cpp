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
    void placeQueen(int currCol)
    {
        
        if(currCol==maxQueens)count++;
        
        for(int i=0;i<maxQueens;i++)
        {
            if(issafe(i,currCol))
            {
                boards[i][currCol]=1;
                row[i]=col[currCol]=uphill[i+currCol]=downhill[i-currCol+maxQueens-1]=1;
                placeQueen(currCol+1);
                row[i]=col[currCol]=uphill[i+currCol]=downhill[i-currCol+maxQueens-1]=0;
                boards[i][currCol]=0;
            }
        }
     }
    
    int totalNQueens(int n) {
        if (n==0)return 0;
        if (n==1)return 1;
        maxQueens=n;
        boards=vector<vector<int>>(n,vector<int>(n,0));
        row=vector<int> (n,0);
        col=vector<int> (n,0);
        uphill=vector<int> (n*2-1,0);
        downhill=vector<int> (n*2-1,0);
        
        placeQueen(0);
        return count;
    }
    
    private:
     int maxQueens;
    vector<vector<int>> boards;
    vector<int> row;
    vector<int> col;
    vector<int> uphill;
    vector<int> downhill;
};

