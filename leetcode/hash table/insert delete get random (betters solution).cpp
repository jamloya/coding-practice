#include<bits/stdc++.h>

using namespace std;
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        return s.insert({val,i}).second?v.push_back(val),i++,true:false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s.find(val)!=s.end())
        {
            
            s[v[v.size()-1]]=s[val];
            v[s[val]]=v[v.size()-1];
            v.pop_back();
            i--;
        }
        return s.erase(val);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand()%s.size()];
    }
private:
    unordered_map<int,int> s;
    vector<int> v;
    int i=0;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
 Solution s;
 cout<<s.();
}

