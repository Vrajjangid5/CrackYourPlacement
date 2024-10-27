class Twitter {
public:

    stack<pair<int,int>>posts;
    unordered_map<int,set<int>>mp;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>v;
        stack<pair<int,int>>st=posts;
        while(st.size() and v.size()!=10){
            pair<int,int>p=st.top();
            st.pop();
            if(p.first==userId or
            mp[userId].find(p.first)!=mp[userId].end() 
            ){
                v.push_back(p.second);
            }
            
        }
        return v;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
