class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0;//minimum sum possible
        int high = 0 ;// maximum sum possible
        for( int i : nums)
        {
            low = max(low,i);
            high+=i;
        }
        while(low<=high)
        {
            int mid = (low + (high-low)/2);
            int count  = 1 ;
            int sum  = 0;
            for(int i : nums)
            {
                 if(sum+i<= mid) sum+=i;
                 else{
                    count++;
                    sum=i;
                 }
            }
            if(count<=k)
            {
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
        
    }
};