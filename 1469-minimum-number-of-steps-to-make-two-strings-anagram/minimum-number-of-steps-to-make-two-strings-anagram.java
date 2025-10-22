class Solution {
    public int minSteps(String s, String t) {
        int[] m  = new int[26];
        for(char c : s.toCharArray())
        {
               m[c-'a']++;
        }
        for( char c : t.toCharArray())
        {
            m[c-'a']--;
        }
        int ans = 0;
        for( int i : m)
        {
            if(i>0) ans+=i;
        }
        return ans;

    }
}