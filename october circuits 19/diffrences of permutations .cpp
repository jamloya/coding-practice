#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    return n==1?1:n*fact(n-1);
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;int f=fact(n);
        cout<<((n*n*f)-((n*(n+1)/2)*f))<<"\n";
    }
}
