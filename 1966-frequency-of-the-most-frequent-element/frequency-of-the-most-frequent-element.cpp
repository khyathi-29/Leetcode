class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left =0;
        int right;
        long numIncrease = 0;
        int ans  = 1;
        for(right =1;right<nums.size();right++){
             numIncrease += 1L*(nums[right]-nums[right-1])*(right-left);
             while(numIncrease > k)
             {
                numIncrease -= 1L*nums[right]-nums[left];
                left++;
             }
             ans = max(ans,right+1-left);
        }
         return ans;
        
    }
};