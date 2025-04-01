class Twitter {
public:
    unordered_map<int,unordered_set<int>> followers;
    unordered_map<int,list<pair<int,int>>> post;
    int time = 1;
    Twitter() {

        
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_front(make_pair(time,tweetId));
        time++;
        
    }
    
    vector<int> getNewsFeed(int userId) {
     unordered_set<int> temp = followers[userId];
     temp.insert(userId);
     auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];  // Sort by timestamp in descending order (max-heap)
        };

    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    unordered_map<int, list<pair<int, int>>::iterator> iterMap;

    for (int id : temp) {
            if (!post[id].empty()) {
                pq.push({post[id].front().first, post[id].front().second, id});
                iterMap[id] = post[id].begin();
            }
        }
   
    vector<int> ans;
    while (!pq.empty() && ans.size() < 10) {
            auto top = pq.top();
            pq.pop();
            ans.push_back(top[1]); // Store tweetId

            int user = top[2];

            // Move iterator forward instead of erasing tweets
            auto it = iterMap[user];
            ++it;
            if (it != post[user].end()) {
                pq.push({it->first, it->second, user});
                iterMap[user] = it;
            }
        }
    return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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