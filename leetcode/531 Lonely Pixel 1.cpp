// 531 Lonely pixels

/*

	Given a picture consisting of black and white pixels, find the number of black lonely pixels.
	The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.
	A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

*/

// this is a optimised Solution but we can also go with a dfs solution.  


#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
	   Solution(){}
	   
	   
	   bool isSingle(pair<int,int> coordinates,vector<vector<char>> &screen)
	   {
	   	 bool flag=true;
			if(coordinates.first-1>=0)
				flag =flag & screen[coordinates.first-1][coordinates.second]=='W';
				
			if(coordinates.first+1<screen.size())
				flag =flag & screen[coordinates.first+1][coordinates.second]=='W';
			
			if(coordinates.second-1>=0)
				flag =flag & screen[coordinates.first][coordinates.second-1]=='W';
				
			if(coordinates.second+1<screen[0].size())
				flag =flag & screen[coordinates.first][coordinates.second+1]=='W';
				
			return flag;
		}
	   
	   //function prototype here
		//O(M*N) -time
		//O(M*N) -space in worst case
	   int findLonelyPixel(vector<vector<char>> &screen)
	   {
	   		if(screen.empty())
	   			return 0;
	   			
	   		vector<pair<int,int>> coordinatesOfBlackPixels;
	   		for(int currentRow=0;currentRow<screen.size();currentRow++)
	   			for(int currentCol=0;currentCol<screen[0].size();currentCol++)
	   				if(screen[currentRow][currentCol]=='B')
	   					coordinatesOfBlackPixels.push_back({currentRow,currentCol});
	   					
	   		int singleBlack=0;
			   
			for(int currentCoords=0;currentCoords<coordinatesOfBlackPixels.size();currentCoords++)	
				if(isSingle(coordinatesOfBlackPixels[currentCoords],screen))
					singleBlack++;
					
			return singleBlack;		
	   }
};

int main()
{
	 Solution s;
	 vector<vector<char>> screen{{'W', 'W', 'B'},{'W', 'B', 'W'},{'B', 'W', 'W'},{'W','B','W'}};
	 clock_t t;
	 t=clock();
	 cout<<s.findLonelyPixel(screen);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

