class Solution {
public:
    int rob(vector<int>& nums) {
      // to get max at a house i we have two cases either pick the i-1th house 
      //i-2th house + cost[i], which ever is maximum.
     if(nums.size()==1) return nums[0];
     if(nums.size()==2) return max(nums[0],nums[1]);
     int n = nums.size();
     int prev1 = nums[0];
     int prev2 = 0;
     int current;
     for(int i=1;i<n;i++)
     {
        current = max(prev2+nums[i],prev1);
        prev2 = prev1;
        prev1 = current;
     }
       return max(prev2,prev1);
    }
};