class Solution {
public:
    int minDistance(string word1, string word2) {
    //1.First we are taking dp vector of size(n+1)*(m+1) to have a base case and 
     //start traversal 1--> n and 1-->m
     //2. We make prev[i]=i and dp[i][0]&& dp[0][i]=i to consider case where one string
     //is empty then number of steps depend on length of other substring 
     //3. since we are doing space optimized one make sure you keep
     // current[0]=i // since it represents dp[i][0]=i indirectly
     //4. Now if alphabets are equal ==> no work needs to be done curr[j]=prev[j-1]
     // depends on numbers of operations till i-1th elemnt in s1 and j-1th element in s2
     //else check for insertion,removal and replace conditions.
     ///////////// donot forget to make prev[i]=i && curr[0]=i;
    
        int n = word1.size();
        int m = word2.size(); 
        if(n==0)return m;
        if(m==0) return n;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> curr(m+1,0),prev(m+1,0);
        for(int i=0;i<m+1;i++)
        {
            prev[i]=i;
            dp[0][i]=i;
        }
        for(int j=0;j<n+1;j++)dp[j][0]=j;
        for(int i=1;i<n+1;i++)
        {
            curr[0]=i;
            for(int j=1;j<m+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];//no change required
                    curr[j]=prev[j-1];
                }
                else
                {
                    dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                   
                    curr[j] = min({prev[j-1], prev[j], curr[j-1]})+1;

                }
            }
            prev = curr;
        }
        return curr[m];
        
    }
};