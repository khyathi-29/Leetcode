class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int low = 1;
        int high = 1;
        for(int i : nums) high = Math.max(high,i);
        int ans = Integer.MAX_VALUE;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int sum = 0;
            for(int i: nums){
                if(i%mid==0) sum+=i/mid;
                else sum +=(i+mid)/mid;
            }
            System.out.println(mid+" ->mid  sum<- "+sum);
            if(threshold<sum) low = mid+1;
            else {
                ans = Math.min(ans,mid);
                high = mid-1;
            }
        }
        return ans;
    }
}