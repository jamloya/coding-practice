class Solution {
public:
    string removeKdigits(string num, int k) {
        string result="";
        for(auto ch:num)
        {
            while(result.length() && result.back()>ch && k )
                result.pop_back(),k--;
            if(result.length() || ch!='0') result.push_back(ch);
        }
        
        while(result.length() && k--)
            result.pop_back();
        return result.length()?result:"0";
    }
};
