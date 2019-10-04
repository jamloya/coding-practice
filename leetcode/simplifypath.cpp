class Solution {
public:
    string simplifyPath(string str) {
        string res="/";
        stack<string> s;
        int last=-1;
        for(int i=0;i<str.size();i++)
        { //cout<<str[i]<<endl;
            if(str[i]=='/')
                {last=i;
                if(i+1<str.size()){
                 if(str[++i]=='.'  ){ if(i+1<str.size()){if(str[++i]=='.' )
                 {   // cout<<s.top();
                     if(s.size()==0){continue;}
                     else{s.pop();}
                 }else{i--;}}}else{i--;}}
                 continue;
                }
            else if( str[i]!='.')
            {   string g=str.substr(i,1);
                while(true){
                    if(str[++i]=='/'){last=i;s.push(g);//cout<<g;
                 if(str[++i]=='.' &&i+1<str.size()){if(str[++i]=='.' &&                          i+2<str.size())
                 {   // cout<<s.top();
                     if(s.size()==0){continue;}
                     else{s.pop();}
                 }else{i--;}}
                                      else{i--;}
                                      break;}
                    g+=str[i];
                }
                
                
            }
            
        }
        //cout<<s.top();
        cout<<last;
        int c=str.size()-last;
        if(s.size()==0){return  str[str.size()-1]=='/' ?res:c<=3?res:str.substr(last,c);}
                       
        res="";
        
        while(!s.empty())
        {
            res="/"+s.top()+res;
            s.pop();
        }
        return res;
    }
};




==============================================================OR=====================================================================
    
    class Solution {
    public:
        string simplifyPath(string str) {
            stack<string> s2;
            for(int i=0;i<str.size();i++)
            {   //cout<<str[i];
                if(str[i]=='/' && i+1<str.size())
                {    //cout<<"l"<<endl;
                    if(str[i+1]=='/' )continue;
                    else{
                      i++;
                      string g=str.substr(i,1);int c=0;int d=0;
                      if(str[i]=='.')c++;
                        i++;
                        while(true)
                            {   //cout<<str[i]<<i<<endl;
                                if(str[i]=='/' || i>=str.size()){break;}
                                else if(str[i]=='.'){g+=str[i]; i++;c++; }
                                else {g+=str[i];i++; d++;}
                            }
                     
                         i--;//cout<<g<<c<<endl;
                        if(c!=2 && c!=1 || d!=0){s2.push(g);}
                        else if(c==2 && s2.size()!=0){s2.pop();}
                    }
                }
            }
            string res="";
            if(s2.size()==0)return "/";
            else{
                while(!s2.empty()){
                res="/"+s2.top()+res;
                s2.pop();}
            }
            return res;
    }
};
