class Solution {
    public int calculate(String s) {
        char op = '+';
        int previous = 0;
        int current =0;
        int ans =0;
        int left = 0;
        while(left<s.length()){
            if(s.charAt(left)<='9' && s.charAt(left)>='0'){
               current =0;
               int i = left;
               while(i< s.length() && s.charAt(i)<='9' && s.charAt(i)>='0')
               {
                 int val = s.charAt(i)-'0';
                 current = current*10 + val;
                 i++;
               }
               left = i-1;
               if(op=='+'){
                ans +=current;
                previous = current;
               }
               else if(op=='-'){
                ans -=current;
                previous = -current;
               }
               else if(op=='*'){
                ans = ans - previous;
                ans += previous*current;
                previous = previous*current;
               }
               else {
                ans = ans - previous;
                ans += previous/current;
                previous = previous/current;
               }
            }
            else if(s.charAt(left)==' '){
            }
            else{
                op = s.charAt(left);
            }
            left++;
        }
        return ans;
        
    }
}