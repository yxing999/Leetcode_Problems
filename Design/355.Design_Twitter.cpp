/*
For every tweet post, add an attribute time to it.
Make use of heap to find the most 10 tweets.
To be unified, add user itself to its followee set.
*/

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        time=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        friends[userId].insert(userId);
        tweets[userId].push_back({time++,tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(auto it=friends[userId].begin();it!=friends[userId].end();it++){
            for(auto a=tweets[*it].begin();a!=tweets[*it].end();a++){
                if(q.size()>=10&&q.top().first>a->first) continue;
                q.push(*a);
                if(q.size()>10) q.pop();
            }
        }
        while(!q.empty()){
            res.insert(res.begin(),q.top().second);
            q.pop();
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            friends[followerId].erase(followeeId);
    }
private:
    int time;
    unordered_map<int,set<int>> friends;
    unordered_map<int,vector<pair<int,int>>> tweets;
};


/*
I will write solution from OOD level when I have some time.
*/



