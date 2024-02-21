class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end = nums.size()-1;
        int start =0;
        return rsearch(nums,target,start,end);
       /* while(start<=end)
        {
            mid = start + (end-start)/2;
            if(target == nums[mid])
            {
                return mid;
            }
            else if(target>nums[mid])
            {
                start = mid +1;
            }
            else
            {
                end = mid-1;
            }
        }*/
        return -1;
    }
    int rsearch(vector<int>& nums, int target, int start, int end)
    {
        if(start > end)
        {
            return -1;
        }
        int mid = start + ((end-start)/2);
        cout<<"mid"<<mid;
        if(target == nums[mid])
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            
            return rsearch(nums,target,mid+1,end);
        }
        else
        {
            return rsearch(nums,target,start,mid-1);
        }
    }
};