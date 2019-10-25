#include<bits/stdc++.h>
using namespace std;
#define input for(int i=0;i<n;i++)cin>>a[i];
int main()
{
    int n,q,l,r,d;
    cin>>n>>q;
   // unordered_map<int,vector<int>> res;
    int a[n];
    input
    vector<int> res;
    while(q--)
    {
        cin>>l>>r>>d;
        if(l==r){
            cout<<1<<"\n";
        }
        else
        {
            int max=INT_MIN,count=1;
            for(int i=l-1;i<r-1;i++)
            { 
                if(a[i+1]-a[i]==d)
                   {    
                       count++;
                   }
                else
                    {
                        if(max<count)
                            {max=count;}
                            count=1;
                    }
            }
            if(max<count)max=count;
            cout<<max<<"\n";
        }
    }
}
