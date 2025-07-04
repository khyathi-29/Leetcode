class Solution {
    public String longestPalindrome(String s) {
        int[] ans = {0,0};
        for(int i =0 ;i<s.length();i++)
        {
            isPalindrome(i,i,s,ans);
            if(i>0) isPalindrome(i-1,i,s,ans);
        }
        return s.substring(ans[0],ans[1]+1);
    }
    void isPalindrome(int i,int j, String s,int[] ans)
    {
        while(i>=0 && j< s.length())
        {
            if(s.charAt(i)==s.charAt(j)){
                if(j-i>= ans[1]-ans[0])
                {
                    ans[1]=j;
                    ans[0]=i;
                }
                i--;
                j++;
            }
            else break;
        }
           return ;
    }
}