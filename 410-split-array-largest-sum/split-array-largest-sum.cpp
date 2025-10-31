class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int minVal = 0;
        int maxVal = 0;
        for(int i : nums)
        {
            minVal = max(minVal,i);
            maxVal+=i;
        }
        int ans = maxVal;
        int i = minVal;
        int j = maxVal;
        while(i<=j)
        {
            int mid = i+(j-i)/2;
            int kk = 1;
            int sum = 0;
            for( int temp : nums)
            {
                if(temp+sum<=mid) sum+=temp;
                else{
                    kk++;
                    sum = temp;
                }
            }
            if(kk<=k){
                ans = min(ans,mid);
                j = mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};