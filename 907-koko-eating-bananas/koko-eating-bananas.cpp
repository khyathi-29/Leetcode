class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1;
        for(int i : piles){
            if(high<i) high = i;
        }
        int ans = high;
        while(low<=high)
        {
            int mid = low + (high -low)/2;
            long hours = 0;
            for(int i : piles)
            {
                hours += (long)i/mid;
                if(i%mid!=0) hours++;
            }
            if(hours>h){
                low = mid+1;
            }
            else {
                ans = min(mid,ans);
                high= mid-1;
            }
            
        }
        return low;
    }
};