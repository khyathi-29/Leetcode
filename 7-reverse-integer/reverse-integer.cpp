class Solution {
public:
    int reverse(int x) {
        int max = (2^31)-1;
        int min = -2^31;

        if(x==0) return x;
        int ans =0;
        while(x!=0){
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            }
            ans = ans*10 + (x%10);
            x=x/10;
        }
        return ans;
    }
};