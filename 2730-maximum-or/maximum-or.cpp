class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n);
        long long pr = 0;
        vector<long long> suf(n);
        for(int i=0;i<n;i++){
             pre[i] = pr;
             pr =pr|nums[i];
        }
        pr = 0;
        for(int i=n-1;i>-1;i--){
             suf[i] = pr;
             pr =pr|nums[i];
        }
        long long maxVal = LONG_MIN;
        for(int i=0;i<n;i++){
            long long temp = (long long) nums[i];
            temp = temp<<k;
            maxVal = max(maxVal,temp|pre[i]|suf[i]);
        }

       return maxVal;
    }
};