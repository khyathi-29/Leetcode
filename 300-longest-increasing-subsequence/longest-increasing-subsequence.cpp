class Solution {
public:
    //We follow bottom up approach Time O(N*N) and Space O(N).
    // we start coming from back initialize all elements of LIS to 1.
    // from back we start a loop and inside the loop we again run a loop from 0 to i-1
    // we check if given element is gretaer than our own element if its greater 
    //then it==> LIS[i]=max(LIS[i],LIS[j]+1(we calculated previsouly+1))
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(),1);
        for(int i=0;i<nums.size();i++)
        {
           for(int j=0;j<i;j++)
           {
             if(nums[j]<nums[i])
             {
                LIS[i]=max(LIS[i],1+LIS[j]);
             }
           }
        }
        int ans=0;
       for(int num:LIS)
       {
         ans = max(ans,num);
       } 
        return ans;
    }
};