class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = searchRangeHelper(nums,target,false);
        int end = searchRangeHelper(nums,target,true);
        return {start,end};
    }
    int searchRangeHelper(vector<int>& nums, int target, bool last)
    {
        int l = 0;
       int h = nums.size()-1;
       int ans = -1;
       while(l<=h)
       {
        int mid = (l+h)>>1;
        if(nums[mid]==target){
             ans = mid;
             if(last==true) l = mid+1;
             else h = mid-1;
        }
        else if(nums[mid]>target) h = mid-1;
        else l = mid+1;
       } 
       return ans;
    }
};