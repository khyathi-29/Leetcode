// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 0;
        int high = n;
        while(low<=high)
        {
            int mid = (low + (high-low)/2);
            bool test = isBadVersion(mid);
            if(test==true) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};