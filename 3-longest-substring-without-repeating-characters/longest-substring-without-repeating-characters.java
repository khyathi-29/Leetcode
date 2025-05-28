class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer> mp = new HashMap<>();
        if(s.length()<=0) return s.length();
        int left =-1;
        int right =0;
        int ans = 0;
        while(right<s.length())
        {
            char c = s.charAt(right);
            if(mp.containsKey(c)==true)
            {
                left = Math.max(mp.get(c),left);
            }
            ans = Math.max(right-left,ans);
            mp.put(c,right);
            right++;
        }
        return ans;
    }
}