#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    unordered_map<char,int> a;
	    unordered_map<char,int> temp;
	    temp['~']=0;
	    temp['^']=0;
	    temp['@']=0;
	    temp['*']=0;
	    temp['&']=0;
	    temp['%']=0;
	    temp['$']=0;
	    temp['#']=0;
	    temp['!']=0;
    	/*temp.insert("$",0);
	    temp.insert("%",0);
    	temp.insert("&",0);
    	temp.insert("*",0);
    	temp.insert("@",0);
    	temp.insert("^",0);
    	temp.insert("`",0);*/
	    char temporary;
	    for(int i=0;i<n;i++)
	    {
	        cin>>temporary;
	        a[temporary]=1;
	    }
	    for(int i=0;i<n;i++)
	    {
	        cin>>temporary;
	        if(a.find(temporary)!=a.end())
	        {
	            temp.find(temporary)->second++;
	        }
	    }
	    string res="";
	    for(auto i=temp.begin();i!=temp.end();i++)
	    {
	        while (i->second>0)
	        {
	            res+=i->first;i->second--;
	            res=res+" ";
	        }
	    }
	    res=res+"\n"+res;
	    cout<<res;
	    cout<<endl;
	}
	return 0;
}
