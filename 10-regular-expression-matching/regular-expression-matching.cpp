class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        // dp[i][j] = whether s[0..i-1] matches p[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;  // empty string matches empty pattern

        // Handle patterns like a*, a*b*, a*b*c* matching empty string
        for (int j = 2; j <= m; j++) {
            if (p[j - 1] == '*' && dp[0][j - 2]) {
                dp[0][j] = 1;
            }
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    // Direct match or dot match
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    // Zero occurrence of preceding char
                    dp[i][j] = dp[i][j - 2];

                    // One or more occurrences
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[n][m]!=0;

    }
};