class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int sum =0;
        int total=0;
        for(int temp : nums){
          sum+=temp;
          if(sum==k) total++;
          if(mp.find(sum-k)!=mp.end()) total+=mp[sum-k];
          mp[sum]++;
        }
        return total;
        
    }
};