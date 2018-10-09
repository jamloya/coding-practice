#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    long long int a,b,c,tot=0;
    string day;
    cin>>a>>b>>day;
    if(day[0]=='1'){
        c=a;
        tot=a;
    }
    c=a;
    for(int i=1;i<day.length();i++)
    {
        c = (c%b*c%b)%b;
        if(day[i]=='1')
        {
            tot=(tot+c)%b;
        }
    }
    cout<<tot%b; 
}
