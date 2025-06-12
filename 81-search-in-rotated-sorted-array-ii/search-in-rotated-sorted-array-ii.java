class Solution {
    public boolean search(int[] nums, int target) {
        int low = 0;
        int high = nums.length-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            System.out.println("low"+low+" high"+high+" mid"+mid);
            if(nums[mid]==target) return true;
             else if(nums[mid]==nums[low] && nums[mid]==nums[high])
            {
                low++;
                high--;
            }
            else if(nums[mid]>=nums[low])
            {
                //left sorted
                // if target is greater than nums[mid] or less than nums[low]
                if(nums[mid]<target || nums[low]>target) low = mid+1;
                else high = mid-1;
            }
            else{
                //right sorted
                // target is less than nums[mid] or greater than nums[high]
                if(target<nums[mid] || nums[high]<target) high = mid-1;
                else low = mid+1;
            }
        }
        return false;
        
    }
}