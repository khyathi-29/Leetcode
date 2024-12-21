class Solution {
public:
// 1 Here time complexity is O(N) space O(1)
// 2.Followed bottom to top approach
// 4.if any number is given example if its between 
//3.if its zero then its consideration depends on number before it so dp[i]=0
//(s[i]=='1' || s[i]=='2' && s[i+1]<'7'
//5. then there are two ways to represent it either individually given by case 
//dp[i]=dp[i+1] or together by taking it as an unit given by dp[i+2]
//6.initillay we take vector with one extra size of string and initilaize it to 1 to start
//and go from back to start and return start value
//7.now instead of taking vector we can do it using last two calculated values as
// we need only i+1th and i+2th element to save space

    int numDecodings(string s) {
        int dp1=1;
        int dp2=0;
        int dp;
        //vector<int> dp(s.size()+1,0);
        //dp[s.size()]=1;
        for(int i=s.size()-1;i>-1;i--)
        {
          if(s[i]=='0') dp=0;//dp[i]=0;
          else
          {
            dp=dp1;//dp[i]=dp[i+1];
            if(i<s.size()-1)
            {
                if(s[i]=='1' || s[i]=='2' && s[i+1]<'7')
                {
                    dp+=dp2;//dp=dp[i+2];
                }
                
            }
          }
          dp2=dp1;
          dp1=dp;
          
        }
        return dp;
    }
};