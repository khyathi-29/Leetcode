class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i : nums){
            m[i]++;
        }
        vector<vector<int>> freq(nums.size()+1);
        for(auto& it : m){
            freq[it.second].push_back(it.first);
        }
        int count=0;
        for(int i = freq.size()-1;i>-1;i--){
            for(int j : freq[i]){
               ans.push_back(j);
               count++;
               if(count==k) return ans;
            }
        }
        return ans;
        
    }
};