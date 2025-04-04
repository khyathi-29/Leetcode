class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if(nums[0]>nums[1]) return 0;
        int n = nums.size()-1;
        if(nums[n]>nums[n-1]) return n;
        int low = 1;
        int high = n-1;
        while(low <=high ){
            int mid = low + ((high-low)/2);
            if(nums[mid]>nums[mid-1] && nums[mid+1]>nums[mid]){
                low = mid+1;
            }
            else if( nums[mid]>nums[mid-1]&& nums[mid]>nums[mid+1]) return mid;
            else high = mid-1;
        }
        return 0;
        
    }
};