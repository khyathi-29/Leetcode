class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int end = -1;
        if(nums.size()==0) return {-1,-1};
        start = Helper(nums,target,true);
        end = Helper(nums,target,false);
        return {start,end};
        
    }
    int Helper(vector<int>& nums, int target, bool val){
        //if val is true then we are searching first position 
        // if val is false we are searching last position
        int low =0;
        int high = nums.size()-1;
        int result = -1;
        while(low<=high)
        {
            int mid = low+ (high-low)/2;
            if(nums[mid]==target){
                result = mid;
                if(val==true) high = mid-1;
                else low = mid+1;
            }
            else if(nums[mid]>target) high = mid-1;
            else low = mid+1;
        }
        return result;
    }
};