class Solution {
    public int reverse(int x) {
        //modulus of -number -ve only
        int reverse = 0;
        int ans = x;
        while(x!=0){
            if(reverse>Integer.MAX_VALUE/10 || reverse<Integer.MIN_VALUE/10){
                return 0;
            }
            reverse = (reverse*10) + x%10;
            x=x/10;
        }
        return reverse;
    }
}