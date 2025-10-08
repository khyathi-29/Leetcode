class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int ans =0;
        int total = 0 ;
        for( int i : nums)
        {
             total +=i;
             if(mp.find(total-k)!=mp.end()) ans+=mp[total-k];
             mp[total]++;

        }
        return ans;
    }
};