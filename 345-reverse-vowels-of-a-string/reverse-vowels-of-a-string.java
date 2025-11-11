class Solution {
    public String reverseVowels(String s) {
        int low = 0;
        int high = s.length() - 1;
        char[] arr = s.toCharArray();

        // set of vowels
        Set<Character> vowels = new HashSet<>(
            Arrays.asList('a','e','i','o','u','A','E','I','O','U')
        );

        while (low < high) {
            // move low forward until we find a vowel
            while (low < high && !vowels.contains(arr[low])) {
                low++;
            }
            // move high backward until we find a vowel
            while (low < high && !vowels.contains(arr[high])) {
                high--;
            }
            // swap vowels
            if (low < high) {
                char temp = arr[low];
                arr[low] = arr[high];
                arr[high] = temp;
                low++;
                high--;
            }
        }
        return new String(arr);
    }
}