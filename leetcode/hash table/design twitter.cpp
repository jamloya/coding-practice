#include<bits/stdc++.h>

using namespace std;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        
        tweets.push_back({tweetId,userId});
        
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int n=tweets.size();
        for(int i=n-1;i>=0 && feed.size()<10;i--)
            if(tweets[i].second==userId  || usersFollowees[userId].find(tweets[i].second)!=usersFollowees[userId].end())
                feed.push_back(tweets[i].first);
        
        return feed;
    
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        usersFollowees[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        usersFollowees[followerId].erase(followeeId);
    }
private:
    
        vector<pair<int,int>> tweets;
        unordered_map<int,unordered_set<int>> usersFollowees;
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

