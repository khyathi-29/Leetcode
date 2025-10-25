class Solution {
    public int arrangeCoins(int n) {
        int l = 0;
        int h = n;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            long sum =(long)mid*(mid+1)/2;
            if(sum==n) return mid;
            else if(sum<n)l = mid+1;
            else h = mid-1;
        }
        return h;
    }
}