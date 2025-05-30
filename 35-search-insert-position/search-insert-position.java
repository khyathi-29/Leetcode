class Solution {
    public int searchInsert(int[] nums, int target) {
        //in Binary search left = number less than target if not found
        //in Binary search right = number greater than target if not found
        int left = 0;
        int right = nums.length-1;
        while(left<=right)
        {
            //System.out.println("left " + left +" right "+right);
            int mid = left + (right-left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
}