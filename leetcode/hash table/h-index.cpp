#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h=0;
        sort(citations.begin(),citations.end());
       for (int i = citations.size()-1; i >= 0; i--) {
            if (citations[i] > h)
                h++;
            else
                break;
        }
        
        return h;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

