#include<bits/stdc++.h>

using namespace std;


//two pointers approach
//O(n)
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        int i(0),j(0);
        while(i<A.size() && j<B.size())
        {
            if(max(A[i][0],B[j][0])<=min(A[i][1],B[j][1]))
                result.push_back({max(A[i][0],B[j][0]),min(A[i][1],B[j][1])});
            A[i][1]<B[j][1]?i++:j++;
        }
        return result;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

