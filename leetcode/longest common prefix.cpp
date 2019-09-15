
bool compare (string &s1,string &s2){
         return s1.size() < s2.size();
    }
class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.size()==0){return "";}
           if(strs.size()==1){return strs[0];}
    	sort(strs.begin(), strs.end(), compare); 
        string prefix="";
        for(int i=1;i<=strs[0].size();i++)
        {   //cout<<i;
            bool flag=false;
            for(int j=1;j<strs.size();j++)
            {  //cout<<strs[0].substr(0,i)<<" "<<strs[j].substr(0,i)<<endl;
                if(strs[0].substr(0,i)==strs[j].substr(0,i));
                else{flag=true;j=strs.size();}
            }
            if(!flag){
                prefix=strs[0].substr(0,i);
            }
            
        }
        return prefix;
    }
};
