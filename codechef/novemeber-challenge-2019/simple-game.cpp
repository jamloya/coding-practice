#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long ans=0,temp;
        int n,m=0;
        cin>>n;
        int arr[n]={0};
        int index=0;
        for (int i=0;i<n;i++)
        {   vector<int> a;
            //for(int j=0;j<m;j++)cout<<a[j];
            cin>>m;
            //cout<<m;
            for(int j=0;j<m;j++)
            {
                cin>>temp;
                a.push_back(temp);
            }
            
            for(int j=0;j<m/2;j++)
            {
                ans+=a[j];
            }
            if(m%2==1)
            {
                arr[index++]=a[(m/2)];
            }
            //cout<<m;
        }
        sort(arr,arr+n);
        //for(int i=0;i<n;i++)cout<<arr[i];
        for(int i=n-1;i>=n-index;i-=2)
        {
            ans+=arr[i];
        }
        cout<<ans<<"\n";
        
        
    }
}
