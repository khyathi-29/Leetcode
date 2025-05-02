class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] ans = new int[nums.length];
        int prefix =1;
        int suffix =1;
        for(int i=0;i<nums.length;i++){
            ans[i]=prefix;
            prefix*=nums[i];
        }
        for(int i=nums.length-1;i>-1;i--){
            ans[i]=suffix*ans[i];
            suffix*=nums[i];
        }
        return ans;
    }
}