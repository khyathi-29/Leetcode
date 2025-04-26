class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int it:nums) mp[it]++;
        vector<vector<int>> freq(nums.size()+1);
        for(auto& i : mp){
            freq[i.second].push_back(i.first);
        }
        vector<int> ans;
        for(int i = freq.size()-1;i>-1;i--){
            for(int j : freq[i]){
                ans.push_back(j);
                k--;
                if(k<1) return ans;
            }
        }
        return ans;
    }
};