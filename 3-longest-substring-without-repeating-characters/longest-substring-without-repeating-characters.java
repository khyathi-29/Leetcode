class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] charIndex = new int[128];
        Arrays.fill(charIndex,-1);
        int start = -1;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(charIndex[c]!=-1){
                start = Math.max(charIndex[c],start);
            }
            charIndex[c]=i;
            ans = Math.max(ans,charIndex[c]-start);
        }
        return ans;
    }
}