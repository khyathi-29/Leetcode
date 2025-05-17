class Solution {
    public int[] sortedSquares(int[] nums) {
        int i;
        int k=0;
        int[] ans = new int[nums.length];
        for(i=0;i<nums.length;i++){
            if(nums[i]>=0) break;
        }
        int j=i-1;
        while(j>-1 && i< nums.length)
        {
            if(nums[j]*nums[j]>nums[i]*nums[i]){
                ans[k]=nums[i]*nums[i];
                k++;
                i++;
            }
            else{
                ans[k]=nums[j]*nums[j];
                k++;
                j--;
            }
        }
        while(j>-1){
             ans[k]=nums[j]*nums[j];
                k++;
                j--;
        }
        while(i<nums.length){
             ans[k]=nums[i]*nums[i];
                k++;
                i++;
        }
        return ans;
        
    }
}