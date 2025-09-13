class Solution {
    public int search(int[] nums, int target) {
       int low = 0;
        int high = nums.length-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            System.out.println("low"+low+" high"+high+" mid"+mid);
            if(nums[mid]==target) return mid;
            else if(nums[mid]>=nums[low])
            {
                //left sorted
                if(nums[mid]<target || nums[low]>target) low = mid+1;
                else high = mid-1;
            }
            else{
                //right sorted
                if(target<nums[mid] || nums[high]<target) high = mid-1;
                else low = mid+1;
            }
        }
        return -1; 
    }
}