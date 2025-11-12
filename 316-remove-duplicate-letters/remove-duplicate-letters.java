class Solution {
    public String removeDuplicateLetters(String ss) {
        int[] freq = new int[26];
        boolean[] seen = new boolean[26];
        Stack<Character> s = new Stack<>();
        for( char c : ss.toCharArray())
        {
              freq[c-'a']++;
        }
        for( char c : ss.toCharArray())
        {
            freq[c-'a']--;
            if(seen[c-'a']==true) continue;
            while(s.isEmpty()==false && s.peek()>c && freq[s.peek()-'a']>0)
            {
                seen[s.peek()-'a']=false;
                s.pop();
            }
            s.add(c);
            seen[c-'a']=true;

        }
        StringBuilder sb = new StringBuilder("");
        while(!s.isEmpty()){
            sb.append(s.pop());
        }
        return sb.reverse().toString();
    }
}