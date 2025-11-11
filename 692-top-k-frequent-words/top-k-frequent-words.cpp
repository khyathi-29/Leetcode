class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        vector<string> ans;
        for( string s : words)
        {
            mp[s]++;
        }
        vector<vector<string>> temp(words.size()+1);
        for(auto i = mp.begin() ;i!=mp.end();i++)
        {
            int freq = i->second;
            string s = i->first;
            temp[freq].push_back(s);
        }
        for(int i = words.size() ;i>-1;i--)
        {
            for(string s : temp[i])
            {
                  k--;
                  ans.push_back(s);
                  if(k==0) return ans;
            }
        }
        return ans;
    }
};