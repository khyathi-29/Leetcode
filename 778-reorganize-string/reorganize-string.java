class Solution {
    String reorganizeString(String s) {
       int[] freq = new int[26];
       for(char c : s.toCharArray())
       {
        freq[c-'a']++;
       }
       int maxfreq = 0;
       int maxchar = 0;
       for(int i=0;i<26;i++)
       {
        if(freq[i]>maxfreq){
            maxfreq = freq[i];
            maxchar = i;
        }
       }
       
       StringBuilder sb = new StringBuilder(" ".repeat(s.length()));
       if(maxfreq>(1+s.length())/2) return "";
       int i =0;
       while(i<s.length() && maxfreq>0)
       {    
            sb.setCharAt(i,(char)('a'+maxchar));
            maxfreq--;
            i=i+2;

       }
       freq[maxchar]=0;
       int j =0;
       while(i<s.length() && j<26)
       {
         if(freq[j]>0)
         {
            sb.setCharAt(i,(char) ('a' + j));
            freq[j]--;
            i=i+2;
         }
         else j++;
       }
       i=1;
        while(i<s.length() && j<26)
       {
         if(freq[j]>0)
         {
            sb.setCharAt(i,(char) ('a' + j));
            freq[j]--;
            i=i+2;
         }
         else j++;
       }
       return sb.toString();
    }
};