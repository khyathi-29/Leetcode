class Solution {
    public int characterReplacement(String s, int k) {
        int[] freq = new int[26];
        int maxfreq = 0;
        int left = 0;
        int right = 0;
        int maxLen = 0;
        while(right<s.length())
        {
            freq[s.charAt(right)-'A']++;
            maxfreq = Math.max(maxfreq,freq[s.charAt(right)-'A']);

            while(right-left+1>maxfreq + k)
            {
                freq[s.charAt(left)-'A']--;
                left++;
            }
            maxLen = Math.max(right-left+1,maxLen);
            right++;
        }
        return maxLen;
    }
}