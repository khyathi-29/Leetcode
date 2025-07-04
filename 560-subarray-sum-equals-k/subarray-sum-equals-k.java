class Solution {
    public int subarraySum(int[] nums, int k) {
        int sum = 0;
        int ans = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i : nums)
        {
            sum+=i;
            if(sum==k) ans++;
            if(mp.get(sum-k)!=null) ans +=mp.get(sum-k);
            mp.put(sum,mp.getOrDefault(sum,0)+1);
        }
        return ans;
    }
}