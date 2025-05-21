class Solution {
    public int rob(int[] nums) {
        int last2= 0;
        int last1 = 0;
        int ans = 0;
        if(nums.length==1) return nums[0];
        for(int i=0;i<nums.length-1;i++){
            ans = Math.max(last1,last2+nums[i]);
            last2 = last1;
            last1 = ans;
        }
        last2=0;
        last1=0;
        int ans2=0;
        for(int i=1;i<nums.length;i++){
            ans2 = Math.max(last1,last2+nums[i]);
            last2 = last1;
            last1 = ans2;
        }
       return Math.max(ans,ans2);
    }
}