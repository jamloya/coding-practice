# define NO_OF_CHARS 256
class Solution {
public:
    bool match(string str1,string str2)
    {
        
    int count[NO_OF_CHARS] = { 0 }; 
    int i;
    for (i = 0; str1[i] && str2[i]; i++) { 
        count[str1[i]]++; 
        count[str2[i]]--; 
    }
    if (str1[i] || str2[i]) 
        return false; 
    for (i = 0; i < NO_OF_CHARS; i++) 
        if (count[i]) 
            return false; 
    return true;
    }
    int cal(string s)
    {
        int temp=0;
        for(int i=0;i<s.size();i++)
        {
            temp+=int(s[i]);
        }
        return temp;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int,vector<string>> m1;
        int ncount=-1;
        for(auto i=0;i<strs.size();i++)
        {
            if(!strs[i].size()){vector<string> t;auto it=m1.find(0);
                                if(it==m1.end())
                                { t.push_back(strs[i]);
                       m1.insert(make_pair(0,t));}
                                else
                                {
                                    it->second.push_back(strs[i]);
                                }continue; }
            int temp=cal(strs[i]);
            auto it=m1.find(temp);
            if(it==m1.end())
            {
                vector<string> t;
                t.push_back(strs[i]);
                m1.insert(make_pair(temp,t));
            }
            else
            {
                    it->second.push_back(strs[i]);   
            }
        }
        
        vector<vector <string>> result;
        //if (count==strs.size()){ result.push_back(strs);
         //                      return result;}
        for(auto it=m1.begin();it!=m1.end();it++)
        {
            //for(int i=0;i<it->second.size();i++){cout<<it->second[i]<<" ";}cout<<endl;
            //result.push_back(it->second);
            if(it->second.size()==1){result.push_back(it->second);}
            else{vector<string> temp;
                 temp.push_back(it->second[0]);
                 string ch=it->second[0];
                 it->second.erase(it->second.begin());int c=0;
                while(it->second.size())
                {
                    if(c==it->second.size()){ch=it->second[0];
                                             result.push_back(temp);
                                             temp.clear();
                                             temp.push_back(ch);
                                            
                                             it->second.erase(it->second.begin());
                                                 c=0;}
                    else
                    {
                        if(match(ch,it->second[c]))
                        {
                            temp.push_back(it->second[c]);
                            //cout<<c;
                            it->second.erase(it->second.begin()+c);
                        }
                        else
                        {
                            c++;
                        }
                    }
                }
                 result.push_back(temp);
            }
        }
        return result;
    }
};
