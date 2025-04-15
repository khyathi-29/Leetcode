class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int ans= INT_MAX;
        while(low<=high)
        {
             int mid = low + (high-low)/2;
             if(nums[low]<=nums[high]){
                //its sorted
                ans = min(ans,nums[low]);
                break;
             }
             else if(nums[mid]<=nums[high]){
                //its sorted on right side but left side can have small element
                ans=min(ans,nums[mid]);
                high = mid-1;
             }
             else{
                ans = min(nums[low],ans);
                low = mid+1;
             }
        }
        return ans;
    }
};