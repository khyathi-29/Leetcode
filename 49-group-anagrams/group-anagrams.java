class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> mp = new HashMap<>();
        List<List<String>> ans = new ArrayList<>();
        for( String s : strs)
        {
             int[] freq = new int[26];
            for(Character ch : s.toCharArray())
            {
                freq[ch-'a']++;
            }
            StringBuilder sb= new StringBuilder("");
            for(int i=0;i<26;i++)
            {
               sb = sb.append( i+","+freq[i]+",");
            }
            if(mp.get(sb.toString())==null){
                 mp.put(sb.toString(),new ArrayList<>());
            }
            mp.get(sb.toString()).add(s);

        }
        
        return new ArrayList<>(mp.values());
    }
}