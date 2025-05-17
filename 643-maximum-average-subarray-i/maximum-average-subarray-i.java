class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int sum=0;
        double ans = Double.NEGATIVE_INFINITY;
        for(int i=0;i<nums.length;i++){
             sum+=nums[i];
             if(i>=k-1){
                if(i-k>-1)sum = sum-nums[i-k];
                ans = Math.max((double)sum/k,ans);
             }
        }
        return ans;
        
    }
}