class Solution {
    public int findShortestSubArray(int[] nums) { 
        int maxFreq = 0;
        int ans = nums.length;
        Map<Integer,Integer> left = new HashMap<>(),right = new HashMap<>(),count = new HashMap<>();
        for(int i=0;i<nums.length;i++)
        {
            int x = nums[i];
            if(left.get(x)==null) left.put(x,i);
            right.put(x,i);
            count.put(x,count.getOrDefault(x,0)+1);
        }
        for( int i : count.values()) maxFreq = Math.max(maxFreq,i);
        for( int x : count.keySet())
        {
            if(count.get(x)==maxFreq) ans = Math.min(ans,right.get(x)+1-left.get(x));
        }
        return ans;
    }
}