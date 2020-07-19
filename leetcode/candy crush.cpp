#include<bits/stdc++.h>

using namespace std;

class TreeNode
{
 public:
	  int val;
	  TreeNode *left,*right;

 TreeNode(int value) : val(value),left(nullptr),right(nullptr){}
};




class Solution{
public:
	   Solution(){}
	   
	   //function prototype here
	vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        const auto R = board.size(), C = board[0].size();
        bool changed = true;
         
        while (changed) {
            changed = false;
             
            for (int r = 0; r < R; ++r) {
                for (int c = 0; c + 2 < C; ++c) {
                    auto v = abs(board[r][c]);
                    if (v != 0 && v == abs(board[r][c + 1]) && v == abs(board[r][c + 2])) {
                        board[r][c] = board[r][c + 1] = board[r][c + 2] = -v;
                        changed = true;
                    }
                }
            }
             
            for (int r = 0; r + 2 < R; ++r) {
                for (int c = 0; c < C; ++c) {
                    auto v = abs(board[r][c]);
                    if (v != 0 && v == abs(board[r + 1][c]) && v == abs(board[r + 2][c])) {
                        board[r][c] = board[r + 1][c] = board[r + 2][c] = -v;
                        changed = true;
                    }
                }
            }
            
            
            for (int c = 0; c < C; ++c) {
                int empty_r = R - 1; 
                for (int r = R - 1; r >= 0; --r) {
                    if (board[r][c] > 0) {
                        board[empty_r--][c] = board[r][c];
                    }
                }
                for (int r = empty_r; r >= 0; --r) {
                    board[r][c] = 0;
                }
            }
            
            for(auto i:board)
            {
            	for(auto j:i)
            		cout<<j<<" ";
            	cout<<endl;
			}
            cout<<endl;
            
            
        }
         
         
         
        return board;
    }
};




int main()
{
	 Solution s;
	 vector<vector<int>> board{  {110,005,112,113,114},
	 							 {210,211,005,213,214},
								 {310,311,003,313,314},
								 {410,411,412,005,414},
								 {005,001,512,003,003},
	 							 {610,004,001,613,614},
								 {710,001,002,713,714} ,
								 {810,001,002,001,001},
								 {001,001,001,002,002},
								 {004,001,004,004,1014}};
	 clock_t t;
	 t=clock();
	 s.candyCrush(board);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

