class Solution {
public:
     //1.First we are taking dp vector of size(n+1)*(m+1) to have a base case and 
     //start traversal 1--> n and 1-->m
     //2. If we found element two be same then dp[i][j]==1+ dp[i-1][j-1]
     //(common substring till 1-i-1 in s1 and 1-j-1 in s2)
     //3. we return dp[n][m]
     // 4.we can make it space optimized also using current and previous.
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size()+1;
        int m = text2.size()+1;
        vector<int> curr(m,0),prev(m,0);
        vector<vector<int> >dp(n,vector<int>(m,0));
        
            for(int i=1;i<n;i++)
            {
                for(int j=1;j<m;j++)
                {
                    if(text1[i-1]==text2[j-1]) {
                    dp[i][j]=dp[i-1][j-1]+1;
                    curr[j]=prev[j-1]+1;
                    }
                    else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    curr[j]=max(curr[j-1],prev[j]);
                     }
                } 
                prev = curr;
            }
        

      return curr[m-1];//dp[n-1][m-1];
        
    }
};