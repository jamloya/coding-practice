#include<bits/stdc++.h>

using namespace std;

class users{
    public:
            unordered_set<int> followee;
            int last_tweet=0;
    
        void follow(int followeeId){
            followee.insert(followeeId);
        }
        void unfollow(int followeeId)
        {
            followee.erase(followeeId);
        }
};

class Twitter {
    
public:   
    
    /** Initialize your data structure here. */
    Twitter() {
        tweets.push_back({0,0});
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets.push_back({usersfollow[userId].last_tweet,tweetId});
        usersfollow[userId].last_tweet=tweets.size()-1;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<int> last;
        if(usersfollow[userId].last_tweet)
            last.push(usersfollow[userId].last_tweet);
        auto i=usersfollow[userId];
            for(auto j:i.followee)
                if(usersfollow[j].last_tweet)
                    last.push(usersfollow[j].last_tweet);
        vector<int> feed;
        while(!last.empty() && feed.size()<10)
        {
            auto top=tweets[last.top()];
            feed.push_back(top.second);
             last.pop();
              if (top.first) {
                last.push(top.first);
              }
        }
        return feed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            usersfollow[followerId].follow(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        usersfollow[followerId].unfollow(followeeId);
    }
private:
    unordered_map<int,users> usersfollow;
    vector<pair<int,int>> tweets;

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main()
{
 Solution s;
 cout<<s.();
}

