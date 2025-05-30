class Solution {
    public String frequencySort(String s) {
        Map<Character,Integer> mp = new HashMap<>();
        int maxFreq = 0;
        for(char c : s.toCharArray())
        {
            mp.put(c,mp.getOrDefault(c,0)+1);
            maxFreq = Math.max(mp.get(c),maxFreq);
        }
        List<Character>[] ls = new ArrayList[maxFreq+1];
        for(Map.Entry<Character,Integer> entry : mp.entrySet())
        {
            char a = entry.getKey();
            int f = entry.getValue();
            if(ls[f]==null) ls[f]=new ArrayList<>();
            ls[f].add(a);
        }
        StringBuilder sb = new StringBuilder();
        for(int i = ls.length-1;i>-1;i--)
        {
            int count = i;
            if(ls[i]!=null){
            for(int j=0;j<ls[i].size();j++)
            {
                int k = 0;
                while(k<i)
                {
                    sb.append(ls[i].get(j));
                    k++;
                }
            }
            }
        }
        return sb.toString();
    }
}