class Solution {
    public int longestBeautifulSubstring(String word) {
        int n = word.length();
        int ans = 0;
        int i = 0;

        while (i < n) {
            // must start with 'a'
            if (word.charAt(i) != 'a') { i++; continue; }

            int j = i;
            int kinds = 1; // we've seen 'a'

            // extend while vowels are non-decreasing (a..e..i..o..u)
            while (j + 1 < n && word.charAt(j) <= word.charAt(j + 1)) {
                if (word.charAt(j) < word.charAt(j + 1)) {
                    kinds++; // moved to next vowel kind
                }
                j++;
            }

            if (kinds == 5) {
                ans = Math.max(ans, j - i + 1);
            }

            i = j + 1; // jump to next segment
        }
        return ans;
    }
}