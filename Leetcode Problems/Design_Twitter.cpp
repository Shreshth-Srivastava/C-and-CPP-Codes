#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Twitter {
public:
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        int count = 10;
        unordered_set<int> following = m[userId];
        
        for(int i = posts.size() - 1; i>=0 ;i--){
            if(count == 0) break;

            int followingId = posts[i].first;
            int tweetId = posts[i].second;
            if(following.count(followingId) || followingId == userId){
                res.push_back(tweetId);
                count--;
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        m[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        m[followerId].erase(followeeId);
    }
private:
    vector<pair<int,int>> posts;
    unordered_map<int, unordered_set<int>> m;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */