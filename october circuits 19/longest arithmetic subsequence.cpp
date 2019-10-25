#include<bits/stdc++.h>
using namespace std;

bool flag=false;
void print(vector<int> a)
{
    if(a.size()<=2)
    {
        for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
    }
    else
    {
        vector<int> temp,temp1;
        for(int i=0;i<a.size()-1;i++)
        {
            temp.push_back(a[i]);
            temp1.push_back(a[++i]);
        }
        if (a.size()%2==1)temp.push_back(a[a.size()-1]);
        if (!flag)
        {print(temp1);
        print(temp); flag=true;}
        else
        {
         print(temp);
        print(temp1); 
        }
        
    }
}

int main()
{
    int k,n;
    cin>>n>>k;
    if(k==n)
    {
        cout<<"Yes\n";
        for(int i=1;i<=n;i++)cout<<i<<" ";
    }
    else
    {
        if(k>n || k==1)
        {
            cout<<"No\n";
        }
        else
        {
            cout<<"Yes\n";
            
            int temp=k;
            for(int i=1;i<k;i++)
            {
                cout<<i<<" ";
            }
            vector<int> a,b;
            for(int i=k;i<n;i++)
            {
                a.push_back(i);
                b.push_back(++i);
            }
            if(n%2==0)a.push_back(n);
            
            //cout<<endl;
            //cout<<a.size()+b.size()<<endl;
            
            print(b);
            flag=false;
            cout<<a[0]<<" ";a.erase(a.begin());
            print(a);
        }
    }
}
