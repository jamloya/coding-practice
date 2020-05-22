#include<bits/stdc++.h>

using namespace std;

class FreqStack {
public:
    
    //map frequency of elements 
    //we basically creates a level of element like in a skip list
    
    
    
    FreqStack() {
    }
    
    void push(int x) {
        maxFrequency=max(maxFrequency,++frequency[x]);
        elements[frequency[x]].push_back(x);
    }
    
    int pop() {
        int val=elements[maxFrequency].back();
        elements[maxFrequency].pop_back();
        if(elements[frequency[val]--].size()==0)
            maxFrequency--;
        return val;
    }
private:
    unordered_map<int,int> frequency;
    int maxFrequency=0;
    unordered_map<int,vector<int>> elements;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
 

int main()
{
 Solution s;
 cout<<s.();
}

