class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i : nums)
        {
            mp.put(i,mp.getOrDefault(i,0)+1);
        }
        List<Integer>[] freq = new ArrayList[nums.length+1];
        for(Map.Entry<Integer,Integer> entry : mp.entrySet())
        {
            int kk = entry.getKey();
            int v = entry.getValue();
            if(freq[v]==null) freq[v]=new ArrayList<>();
            freq[v].add(kk);
        }
        int[] ans = new int[k];
        int i =0;
        int j = freq.length-1;
        while(j>0)
        {
            if(freq[j]!=null)
            {
                for(int t : freq[j])
                {
                    ans[i]=t;
                    i++;
                    k--;
                    if(k==0) return ans;
                    
                }
            }
            j--;
        }
        return ans;
    }
}