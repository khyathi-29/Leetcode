class Solution {
    public int peakIndexInMountainArray(int[] nums) {
        int l = nums.length-1;
        if(nums.length==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[l]>nums[l-1]) return l;
        int low = 1;
        int high = l-1;
        //since we already checked last and first elements and 
        // to not get arraybound exceptions
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[mid-1]&& nums[mid]>nums[mid+1]) return mid;
            else if(nums[mid]>nums[mid-1] && nums[mid+1]>nums[mid])
            {
                //peak might exist towards right
                low = mid+1;
            }
            else if(nums[mid]<nums[mid-1] && nums[mid+1]<nums[mid])
            {
                high = mid-1;
            }
            else{
                //if the element is lowest it can go anyside
                low = mid+1;
            }
        }
        return -1;
    }
}