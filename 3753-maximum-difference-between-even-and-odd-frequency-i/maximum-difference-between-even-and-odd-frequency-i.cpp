class Solution {
public:
    int maxDifference(string s) {
        map<char,int> mp;
        for(char ch : s) mp[ch]++;
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            if(it->second%2==0) minVal = min(minVal,it->second);
            else maxVal = max(maxVal,it->second);
        }
        return maxVal-minVal;
    }
};