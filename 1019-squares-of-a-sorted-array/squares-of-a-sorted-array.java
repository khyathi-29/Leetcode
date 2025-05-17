class Solution {
    public int[] sortedSquares(int[] nums) {
        int i = nums.length-1;
        int k = i;
        int j=0;
        int[] ans = new int[nums.length];
        while(i >= j){
            if(nums[j]*nums[j]>nums[i]*nums[i]){
                ans[k]=nums[j]*nums[j];
                k--;
                j++;
            }
            else{
                ans[k]=nums[i]*nums[i];
                k--;
                i--;
            }
        }
        
        return ans;
        
    }
}