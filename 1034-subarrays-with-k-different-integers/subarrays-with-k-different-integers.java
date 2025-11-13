class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        return subarraysWithKDistinctHelper(nums,k)-subarraysWithKDistinctHelper(nums, k-1);
    }
    public int subarraysWithKDistinctHelper(int[] nums, int k)
    {
        Map<Integer,Integer> mp = new HashMap<>();
        int count = 0;
        int left = 0;
        int right =0;
        while(right<nums.length)
        {
            mp.put(nums[right],mp.getOrDefault(nums[right],0)+1);
            while(mp.size()>k)
            {
                mp.put(nums[left],mp.getOrDefault(nums[left],0)-1);
                if(mp.get(nums[left])==0) mp.remove(nums[left]);
                left++;
            }
            count+=right-left+1;
            right++;
            
        }
        return count;
    } 
}