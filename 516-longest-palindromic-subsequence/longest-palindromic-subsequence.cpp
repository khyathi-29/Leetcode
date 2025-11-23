class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string first = s;
        reverse(s.begin(),s.end());
        string second = s;
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,false));
        for(int i=0;i<first.length();i++){
            for(int j=0;j<second.length();j++){
                if(first[i]==second[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                }
                else dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[n][n];
    }
};