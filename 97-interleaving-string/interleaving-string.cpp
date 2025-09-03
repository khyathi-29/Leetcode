// tabulation 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int s = s3.size();
        if(s!=n+m) return false;

        vector<vector<bool>> dp (n+1,vector<bool>(m+1,false)) ;
         dp[0][0]=true;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                int k = i+j;
                
                if(i>0 && s1[i-1]==s3[k-1]) dp[i][j]=dp[i-1][j] || dp[i][j];
                if(j>0 && s2[j-1]==s3[k-1]) dp[i][j]= dp[i][j-1] || dp[i][j];
            }
            
        }
        return dp[n][m];

    }
};