#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Design Twitter: post tweets, follow/unfollow, see recent tweets

    Maintain user -> tweet pairs & hash map {user -> ppl they follow}

    Time: O(n)
    Space: O(n)
    https://leetcode.com/problems/design-twitter/
*/

class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // 10 tweets
        int count = 10;
        vector<int> result;
        
        // since postTweet pushes to the back, looping from back gets most recent
        for (int i = posts.size() - 1; i >= 0; i--) {
            if (count == 0) {
                break;
            }
            
            int followingId = posts[i].first;
            int tweetId     = posts[i].second;
            unordered_set<int> following = followMap[userId];
            // add to result if they're following them or it's a tweet from themself
            if (following.find(followingId) != following.end() || followingId == userId) {
                result.push_back(tweetId);
                count--;
            }
        }
        
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
private:
    // pairs: [user, tweet]
    vector<pair<int, int>> posts;
    // hash map: {user -> people they follow}
    unordered_map<int, unordered_set<int>> followMap;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */ 
class Twitter_PQ {
private:
    unordered_map<int, unordered_set<int> > friends;
    int timeStamp;
    priority_queue<array<int,3> >timeline;
public:
    Twitter_PQ() {
        friends.clear();
        timeStamp = 0;
        timeline = priority_queue<array<int,3>>();
    }
    
    void postTweet(int userId, int tweetId) {
        timeline.push({timeStamp++, tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        priority_queue<array<int,3>> userTimeline(timeline);
        int n = 0;
        while(!userTimeline.empty() and n < 10) {
            array<int,3> topfeed = userTimeline.top();
            if(topfeed[2] == userId || friends[userId].find(topfeed[2])!=friends[userId].end()){
                res.push_back(topfeed[1]);
                n++;
            }
            userTimeline.pop(); 
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};
int main(){
    
    return 0;
}