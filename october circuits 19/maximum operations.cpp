#include<bits/stdc++.h>
using namespace std;
long long max(long long f,long long s){return f>s?f:s;}
long long xnor(long long a,long long b)
{
    int i=0;long long res=0;
    while(a && b)
    {
       if((a%2==1 && b%2==1) ||(a%2==0 && b%2==0 ))
       {
           res+=pow(2,i)*1;
       }
       a/=2;b/=2;i++;
    }
    return res;
}

int main()
{
    int t;
    cin>>t;
    long long first,second,n;
    long long  a[3],b[3];
    while(t--)
    {
        cin>>first>>second>>n;
        a[1]=first;a[2]=second;a[0]=first^second;
        b[1]=first;b[2]=second;b[0]=xnor(first,second);
        int temp=n%3;
        cout<<max(a[temp],b[temp])<<"\n";
    }
}
