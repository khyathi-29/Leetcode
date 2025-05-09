class Solution {
    public int jump(int[] nums) {
       int left =0;
       int right =0;
       int steps=0;
       int maxreach = 0;
       while(left < nums.length){
         
         for(int i=left;i<=right;i++){
            if(i==nums.length-1) return steps;
            maxreach = Math.max(maxreach,nums[i]+i);
         }
         steps++;
         left = right+1;
         right = maxreach;
       } 
       return steps;
    }
}