class Solution {
    public String reorganizeString(String s) {
       int[] freq = new int[26];
       int half = (s.length()+1)/2;
       int maxfreq = 0;
       for(char c : s.toCharArray())
       {
         freq[c-'a']++;
         maxfreq = Math.max(freq[c-'a'],maxfreq);
       }
       List<int[]> fr = new ArrayList<>();
       for(int i =0;i<freq.length;i++)
       {
        if(freq[i]>0)
        {
            int[] temp = new int[2];
            temp[0]=freq[i];
            temp[1]=i;
            fr.add(temp);
        }
       }
       fr.sort((a,b)->Integer.compare(b[0],a[0]));
       if(maxfreq>half) return "";
       int i =0;
       int j =0;
       StringBuilder sb = new StringBuilder(" ".repeat(s.length()));
       while(i<s.length() && j<fr.size())
       {
        int[] temp = fr.get(j);
         if(temp[0]>0)
         {
            sb.setCharAt(i,(char) ('a' + temp[1]));
            temp[0]--;
            i=i+2;
         }
         else j++;
       }
       i = 1;
       while(i<s.length() && j<fr.size())
       {
         int[] temp = fr.get(j);
         if(temp[0]>0)
         {
            sb.setCharAt(i,(char) ('a' + temp[1]));
            temp[0]--;
            i=i+2;
         }
         else j++;
       }
       return sb.toString();
    }
}