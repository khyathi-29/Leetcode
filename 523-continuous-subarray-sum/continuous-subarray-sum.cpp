class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> Hashmap;
        Hashmap[0]=-1;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int mod = sum%k;
            if(Hashmap.find(mod)!=Hashmap.end()){
                if(i-Hashmap[mod]>1) return true;
            }
            else Hashmap[mod]=i;
        }
        return false;
    }
};