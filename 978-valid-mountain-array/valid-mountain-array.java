class Solution {
    public boolean validMountainArray(int[] nums) {
        if(nums.length<3) return false;
        int low =0;
        int high = nums.length-1;
        int n = nums.length-1;
        if(nums[0]>nums[1]) return false;
        if(nums[high]>nums[high-1]) return false;
        while(low<n-1)
        {
            if(nums[low+1]>nums[low]) low++;
            else if(nums[low]==nums[low+1]) return false;
            else break;
        }
        while(high>0)
        {
            if(nums[high-1]>nums[high]) high--;
            else if(nums[high]==nums[high-1]) return false;
            else break;
        }
        System.out.println(low+ " "+high);
        if(low==high) return true;
        else return false;
    }
}