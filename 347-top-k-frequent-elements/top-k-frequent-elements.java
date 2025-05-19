class Solution {
    public int[] topKFrequent(int[] nums, int k) {
      Map<Integer,Integer> mp = new HashMap<>();
      for(int i : nums){
        mp.put( i, mp.getOrDefault(i,0)+1);
      }
      List<Integer>[] temp = new ArrayList[nums.length+1];
      for(Map.Entry<Integer, Integer> entry : mp.entrySet())
      {
        int freq = entry.getValue();
        if (temp[freq] == null) temp[freq] = new ArrayList<>();
        temp[freq].add(entry.getKey());
      }
      int[] ans = new int[k];
      int j=0;
      for(int kk = nums.length ; kk>-1;kk--)
      {
        if(temp[kk]!=null)
        {
        for(int i : temp[kk])
        {
             ans[j]=i;
             j++;
             if(j==k) return ans;
        }
        }
      }
    return ans;
    }
}