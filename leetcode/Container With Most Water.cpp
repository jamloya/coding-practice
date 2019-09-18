

====================================================Brute Force==================================================

class Solution {
public:
    int maxArea(vector<int>& height) {
        int length=height.size();
        vector<int> vol;
        int volume=0;
        while(length!=1)
        {
            for(int i=0;i+length<=height.size();i++)
            { //cout<<i<<" "<<i+length<<endl;
                //cout<<length<<" "<<min(height[i],height[i+length-1])<<endl;
                volume=(length-1)*min(height[i],height[i+length-1]);
                vol.push_back(volume);
            }
            length--;
        }
        sort(vol.begin(),vol.end(),greater<int>());
        return vol[0];
    }
    int min(int a,int b)
    {
        return a<b?a:b;
    }
};




====================================================O(n) solution=============================================================
    
    class Solution {
    public:
    int maxArea(vector<int>& height) {
        int maxarea=0,l=0,r=height.size()-1;
        while(l<r)
        {
            int newarea=height[l]<height[r]?height[l]*(r-l):height[r]*(r-l);
            maxarea=newarea>maxarea?newarea:maxarea;
            if(height[l]>height[r]) r--;
            else l++;
        }
        return maxarea;
    }
};


