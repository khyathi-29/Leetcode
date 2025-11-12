class Solution {
    public String breakPalindrome(String palindrome) {
        if(palindrome.length()==1 && palindrome.charAt(0)=='a') return "";
        StringBuilder sb = new StringBuilder(palindrome);
        int i =0;
        while(i<palindrome.length()/2)
        {
            if(palindrome.charAt(i)!='a'){
                 sb.setCharAt(i,'a');
                 return sb.toString();
            }
            i++;
        }
        int j = palindrome.length()-1;
        while(j>0){
            if(palindrome.charAt(j)=='a'){
                sb.setCharAt(j,'b');
                 return sb.toString();
            }
            j--;
        }
        return "";
    }
}