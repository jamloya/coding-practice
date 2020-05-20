#include<bits/stdc++.h>

using namespace std;
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        return s.insert(val).second?true:false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return s.erase(val);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vector(s.begin(),s.end())[rand()%s.size()];
    }
private:
    unordered_set<int> s;
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

