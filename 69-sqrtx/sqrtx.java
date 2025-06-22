class Solution {
    public int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int low  = 1;
        int high = x;
        int ans = 1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            long val = (long)mid*mid;
            if(val==x) return mid;
            else if(val<x) low = mid+1;
            else high = mid-1;
        }
        return high;
    }
}