class Solution {
    public String findValidPair(String s) {
        int[] freq = new int[9];
        char[] ch = s.toCharArray();
        StringBuilder sb = new StringBuilder("");
        for( char c : s.toCharArray())
        {
             freq[c-'1']++;
        }
        for( int i=1;i<s.length();i++)
        {
            int fr1 = freq[ch[i-1]-'1'];
            int fr2 = freq[ch[i]-'1'];
            System.out.println(fr1 + " " + fr2);
            if(fr1 == ch[i-1]-'0' && fr2 == ch[i]-'0' && ch[i]!=ch[i-1])
            {
                sb.append(ch[i-1]);
                sb.append(ch[i]);
                return sb.toString();
            }
        }
        return sb.toString();
    }
}