class AuthenticationManager {
public:
    unordered_map<string,int> mp;
    int timeToLive;
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.find(tokenId)!=mp.end() && mp[tokenId]+timeToLive>currentTime){
            mp[tokenId] = currentTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans =0;
        for(auto i = mp.begin();i!=mp.end();i++){

            if(i->second+timeToLive >currentTime) ans++;
        }
        return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */