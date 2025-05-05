class Solution {
    public int minimumOperations(int[] nums) {
        int[] ref = new int[101];
        int ans=0;
        for(int i : nums){
            if(ref[i]==0 && i!=0){
                ref[i]=-1;
                 ans++;
            }
        }
        return ans;
    }
}