class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> m = new HashMap<>();
        int[] ans = {-1,-1};
       
        for(int i=0;i<nums.length;i++){
            if(m.containsKey(target-nums[i])){
                ans[0]=m.get(target-nums[i]);
                ans[1]=i;
                return ans;
            }
            m.put(nums[i],i);
        }
        return ans;
        
    }
}