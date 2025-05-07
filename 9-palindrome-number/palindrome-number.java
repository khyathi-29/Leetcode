class Solution {
    public boolean isPalindrome(int x) {
        if(x<0) return false;
        int ans = x;
        int temp=0;
        while(x>0){
        if(temp> Integer.MAX_VALUE/10) return false;
        temp = temp*10 + (x%10);
        x= x/10;
        }
        return (temp==ans);
    }
}