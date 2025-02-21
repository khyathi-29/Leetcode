class Solution {
public:
    int getSum(int a, int b) {
        int xr = a^b; // to identify sum when one is zero one is one 
        int ab = (a&b)<<1; // to get carry we perform 1 and left shift it by 1
        while(ab!=0){
            int temp = xr; //( xor old)
            xr = xr^ab;//(xor updated)
            ab = (temp&ab)<<1; //(carry updated)
        }
        return xr;
    }
};