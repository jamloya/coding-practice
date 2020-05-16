#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> strength;
        int sum=0;
        for(int i=0;i<mat.size();i++)
         	strength.push_back(make_pair(accumulate(mat[i].begin(),mat[i].end(),sum),i));
    
        
		sort(strength.begin(),strength.end(),
		[&](pair<int,int> p1,pair<int,int>p2){
			return p1.first==p2.first?p1.second<p2.second:p1.first<p2.first;
		});
    
		vector<int> res;
		for(int i=0;i<k;i++)
			res.push_back(strength[i].second);
		return res;
	}
};

int main()
{
	Solution s;
	s.kWeakestRows();
}
