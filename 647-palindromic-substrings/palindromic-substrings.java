class Solution {
    public int countSubstrings(String s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            count+= palindrome(i,i,s);
            if(i>0) count+=palindrome(i-1,i,s);
        }
        return count;
    }
    int palindrome(int i,int j, String s)
    {
        int count =0;
        while(i>-1 && j<s.length())
        {
            if(s.charAt(i)==s.charAt(j))
            {
               count++;
               i--;
               j++;
            }
            else break;
        }
        return count;
    }
}