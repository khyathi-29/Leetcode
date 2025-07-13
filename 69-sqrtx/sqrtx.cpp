class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
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
};