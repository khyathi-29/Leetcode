class Solution {
    public int rob(int[] nums) {
        int last2 = 0;
        int last1 = 0;
        int ans = 0;
        for(int i : nums){
            ans = Math.max(last1+i,last2);
            last1 = last2;
            last2 = ans;
        }
        return ans;
    }
}