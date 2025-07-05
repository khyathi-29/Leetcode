class Solution {
    public String minWindow(String s, String t) {
        if (s.length() < t.length()) return "";

        Map<Character, Integer> f1 = new HashMap<>();  // Frequency map for t
        Map<Character, Integer> f2 = new HashMap<>();  // Frequency map for s window

        for (char c : t.toCharArray()) {
            f1.put(c, f1.getOrDefault(c, 0) + 1);
        }

        int match = f1.size();
        int left = 0, right = 0;
        int start = 0, len = Integer.MAX_VALUE;

        while (right < s.length()) {
            char c = s.charAt(right);
            f2.put(c, f2.getOrDefault(c, 0) + 1);

            if (f1.containsKey(c) && f1.get(c).intValue() == f2.get(c).intValue()) {
                match--;
            }

            while (match == 0) {
                if (right - left + 1 < len) {
                    start = left;
                    len = right - left + 1;
                }

                char leftChar = s.charAt(left);
                f2.put(leftChar, f2.get(leftChar) - 1);

                if (f1.containsKey(leftChar) && f2.get(leftChar) < f1.get(leftChar)) {
                    match++;
                }

                left++;
            }

            right++;
        }

        return len == Integer.MAX_VALUE ? "" : s.substring(start, start + len);

    }
}