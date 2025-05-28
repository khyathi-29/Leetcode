class Solution {
    public String longestPalindrome(String s) {
        int[] ans = {-1,-1};
        for(int i=0;i<s.length();i++){
             if(i>0) isPalindrome(s,i-1,i,ans);
             isPalindrome(s,i,i,ans);
        }
        
        return s.substring(ans[0],ans[1]+1);
    }
    public void isPalindrome(String s, int i, int j,int[] ans)
    {
        while(i>-1 && j<s.length())
        {
           if(s.charAt(i)==s.charAt(j)){
            int len = ans[1]-ans[0];
            if(len<=j-i){
                ans[1]=j;
                ans[0]=i;
            }
            i--;
            j++;
           }
           else return;
        }
        return;
    }
}