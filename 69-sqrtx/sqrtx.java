class Solution {
    public int mySqrt(int x) {
    if(x<2) return x;
    int low = 1;
    int high = x/2;
    long val =0;
    int ans=0;
    while(low<=high){
        int mid = low + (high-low)/2;
        val = (long) mid * mid;
        if(x==val) return mid;
        else if(x<val) high = mid-1;
        else {
            ans = mid;
            low = mid+1;
        }
    }
    return ans;
    }
}