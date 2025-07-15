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
             //since we calculated till before what increase is needed
             // we just need to calculate increase with before element and multiply
             // with the width since now we assume the before elements all values are updated to its value;
             while(numIncrease > k)
             {
                numIncrease -= 1L*nums[right]-nums[left];
                // since we are removing left element we need to subtract increase 
                // it caused
                left++;
             }
             ans = max(ans,right+1-left);
        }
         return ans;
        
    }
};