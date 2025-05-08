class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int max = 0;
        for(int i: piles){
            max = Math.max(i,max);
        }
        int low = 1;
        int high = max;
        int ans =0;
        while(low<=high){
            int mid = low + (high-low)/2;
            long hours =0;
            for(int i: piles){
                hours +=i/mid;
                if(i%mid!=0) hours+=1;
            }
            if(hours>h){
                low = mid+1;
            }
            else {
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
}