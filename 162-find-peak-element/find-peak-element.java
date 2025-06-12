class Solution {
    public int findPeakElement(int[] nums) {
       if(nums.length<2) return 0;
       int low = 1;
       int high = nums.length-2;
       if(nums[low]<nums[0]) return 0;
       if(nums[high]<nums[high+1]) return high+1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if(nums[mid]>nums[mid-1] && nums[mid+1]>nums[mid]) low = mid+1;
            else high = mid-1;
        }
        return -1; 
    }
}