class Solution {
public:
   void insertHash(string s,vector<char>& hashArr)
    {   
       hashArr.push_back('#');
        
        for(int i=0;i<s.size();i++)
        {
            hashArr.push_back(s[i]);
            hashArr.push_back('#');
        }
            hashArr.pop_back();
        
    }
    
    int palindromelength(vector<char>& hashArr,int index,int length){
        int start=index-length-1;
        int last=index+length+1;
        while(start>=0 && last<hashArr.size())
        { 
            if(hashArr[start--]==hashArr[last++])
            {
                length++;
            }else
            {  
                break;
            }
        }
        return length;
    }
    
    string longestPalindrome(string s) {
        if (s.size()==0){return "";}
        if(s.size()==1){return s;}
        vector<char> hashArr;
        insertHash(s,hashArr);
        int n=hashArr.size();
        int length[n]={0};
        
        int rightBoundary=0;
        int center=0;
        int maxIndex=0;
        length[0]=0;
        for(int i=1;i<n;i++)
        { 
            int mirror;
         if(2 * center - i>=0)
         { mirror=length[2 * center - i];}
            else{
                 mirror=length[center];
            }
         
            
            if(i<rightBoundary){
                length[i]=min(rightBoundary-i,mirror);
            }
         
            length[i]=palindromelength(hashArr,i,length[i]);
            
            if(i+length[i]>rightBoundary)
            {
                center=i;rightBoundary=i+length[i];
            }
            if(length[maxIndex]<=length[i])
            {  
                maxIndex=i;
            }
         
        }
        
        
        int start=maxIndex-length[maxIndex];
        int last=maxIndex+length[maxIndex];
        string res="";
        for(int i=start;i<=last;i++)
        {
            if(hashArr[i]=='#')
            {
                continue;
            }
            res+=hashArr[i];
        }
        return res;
        
    }
};
