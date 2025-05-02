class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> mp = new HashMap<>();
       for(String s : strs){
           int[] freq = new int[26];
           for(char c : s.toCharArray()){
                 freq[c-'a']++;
           }
           StringBuilder sb = new StringBuilder();
           for(int i : freq){
              sb.append("#");
              sb.append(i);
           }
           if(mp.containsKey(sb.toString())==false){
            mp.put(sb.toString(),new ArrayList<String>());
           }
           mp.get(sb.toString()).add(s);
       } 
       return new ArrayList(mp.values());
    }
}