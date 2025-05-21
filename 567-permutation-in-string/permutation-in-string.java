class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int[] f1 = new int[26];
        int[] f2 = new int[26];
        if(s1.length()>s2.length()) return false;
        for(int i=0;i<s1.length();i++){
            f1[s1.charAt(i)-'a']++;
            f2[s2.charAt(i)-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(f1[i]==f2[i]) count++;
        }
        if(count==26) return true;
        for(int i = s1.length();i<s2.length();i++)
        {
            int before = i-s1.length();
            char be = s2.charAt(before);
            int now = i;
            char no = s2.charAt(now);
            //1.if it was a match before since we are moving 1 step 
            //count--
            if(f1[be-'a']==f2[be-'a']) count--;
            //2. If current added element freq before updating is match
            // now if won't be match now
            if(f1[no-'a']==f2[no-'a']) count--;

            f2[no-'a']++;//adding element
            f2[be-'a']--;//removing element

            if(f1[no-'a']==f2[no-'a']) count++;
            if(f1[be-'a']==f2[be-'a']) count++;

            if(count==26) return true;

        }
        return false;
        
    }
}