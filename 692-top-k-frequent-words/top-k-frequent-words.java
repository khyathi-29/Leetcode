class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        List<String> ans = new ArrayList<>();
        Map<String,Integer> mp = new TreeMap<>();
        int n = words.length;
        for(String s : words)
        {
            mp.put(s,mp.getOrDefault(s,0)+1);
        }
        List<String>[] temp= new ArrayList[n];
        for(Map.Entry<String, Integer> entry : mp.entrySet())
        {
            int kk = entry.getValue();
            String s = entry.getKey();
            if(temp[kk]==null) temp[kk]= new ArrayList<>();
            temp[kk].add(s);
        }
        for(int i = temp.length-1;i>-1;i--)
        {
            if(temp[i]!=null)
            {
                for( String s : temp[i])
                {
                    ans.add(s);
                    k--;
                    if(k==0) return ans;
                }
            }
        }
        return ans;
    }
}