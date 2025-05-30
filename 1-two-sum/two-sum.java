class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> mp = new HashMap<>();
        int[] ans = new int[2];
        for(int i=0;i<nums.length;i++){
            if(mp.containsKey(target-nums[i])){
                ans[0]=mp.get(target-nums[i]);
                ans[1]=i;
                return ans;
            }
            else{
                mp.put(nums[i],i);
            }
        }
        return ans; 
    }
}