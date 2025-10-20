class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int low =0;
       int high = nums.size()-1;

       while(low<=high)
       {
         int mid = (low+high)>>1;
         if(nums[mid]==target) return true;
         else if(nums[mid]==nums[high] && nums[mid]==nums[low])
         {
            high--;
            low++;
         }
         else if( nums[mid]<=nums[high])
         {
             if(nums[mid]<target && target<=nums[high])
             {
                low = mid+1;
             }
             else high = mid-1;
         }
         else {
            if(nums[mid]>target && target>=nums[low])
             {
                high = mid-1;
             }
             else low =mid+1;
         }
       }
      return false;
    }
};