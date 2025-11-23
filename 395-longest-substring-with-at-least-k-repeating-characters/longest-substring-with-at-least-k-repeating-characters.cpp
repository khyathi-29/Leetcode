class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        return helper(0,n-1,s,k);
    }
    int helper(int low, int high,string s, int k) {
        if (high - low + 1 < k) return 0;
        vector<int> freq(26, 0);
        for (int i = low; i <= high; ++i)
            freq[s[i] - 'a']++;
        
        for (int i = low; i <= high; ++i) {
            if (freq[s[i] - 'a'] < k) {
                int left = helper( low, i - 1,s, k);
                int right = helper(i + 1, high,s, k);
                return max(left, right);
            }
        }
        cout<<high<<" "<<low<<endl;
        return high - low + 1;
    }
};