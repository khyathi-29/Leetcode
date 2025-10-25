class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int h = x;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            long val =(long)mid*mid;
            if(val<=x)
            {
                l = mid+1;
            }
            else h = mid-1;
        }
        return h;
    }
};