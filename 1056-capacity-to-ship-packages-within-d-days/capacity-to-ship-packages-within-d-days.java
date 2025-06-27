class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int low = 1;
        int high = 0;
        for(int i: weights){
           high +=i;
           low = Math.max(low,i);
        } 
        int ans = high;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int dayCount = 0;
            int sum = 0;
            for(int i : weights)
            {
                sum += i;
                if(sum>mid){
                    sum = i;
                    dayCount++;
                }
            }
            dayCount++;
            if( dayCount <= days)
            {
                   ans = Math.min(ans,mid);
                   high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
}