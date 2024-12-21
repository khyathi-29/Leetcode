class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int current1;
        int prev1=nums[0];
        int prev2=0;
        //checking for houses 1 to n-1
        for(int i=1;i<n-1;i++)
        {
            current1 = max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=current1;
        }
        current1 = max(prev1,prev2);
       //checking for houses 2 to n-2
       int current2;
       prev1 = nums[1];
       prev2=0;
       for(int i=2;i<n;i++)
        {
            current2 = max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=current2;
        }
        current2 =max(prev1,prev2);
      return max(current1,current2);
    }
};