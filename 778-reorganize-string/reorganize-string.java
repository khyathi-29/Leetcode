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
       int n = s.length();
       char[] res = new char[n];
       if(maxfreq>(1+n)/2) return "";
       int i =0;
       while(i<n && maxfreq>0)
       {    
            res[i]= (char)('a'+maxchar);
            maxfreq--;
            i=i+2;

       }
       freq[maxchar]=0;
       int j =0;
       while(j<26)
       {
         if(i>=n) i = 1;
         if(freq[j]>0)
         {
            res[i]= (char)('a'+j);
            freq[j]--;
            i=i+2;
         }
         else j++;
       }
       return new String(res);
    }
};