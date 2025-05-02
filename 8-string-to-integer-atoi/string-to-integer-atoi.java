class Solution {
    public int myAtoi(String s) {
        int i=0;
        int sign = 1;
        int ans = 0;
        if(s.length()==0) return 0;
        while(i<s.length() && s.charAt(i)==' '){
            i++;
        } 
        if(i<s.length() && s.charAt(i)=='-' ){
            i++;
            sign = -1;
        } 
        else if(i<s.length() && s.charAt(i)=='+' ){
              i++;
        } 
        while(i<s.length() && Character.isDigit(s.charAt(i))){
           int val = s.charAt(i)-'0';
           if(ans>Integer.MAX_VALUE/10 || (ans==Integer.MAX_VALUE/10 && val>Integer.MAX_VALUE%10)){
              return sign==1?Integer.MAX_VALUE:Integer.MIN_VALUE;
           }
           ans = ans*10+val;
           i++;
       }
       return ans*sign;
    }
}