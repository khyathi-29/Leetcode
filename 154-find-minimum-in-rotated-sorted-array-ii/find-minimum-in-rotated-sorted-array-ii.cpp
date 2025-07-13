class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int ans = nums[low];
        while(low<=high)
        {
            int mid = (low+(high-low)/2);
            cout<<mid<<endl;
            if(nums[mid]==nums[low] && nums[high]==nums[low])
            {
                ans = min(nums[low],ans);
                high--;
                low++;
            }
            else if(nums[low]<=nums[mid] && nums[mid]<=nums[high])
            {
                ans = min(nums[low],ans);
                cout<<"2"<<endl;
                break;
            }
            else if(nums[low]<=nums[mid])
            {
                ans = min(ans,nums[low]);
                cout<<"3"<<endl;
                low = mid+1;
            }
            else{
                ans = min(ans,nums[mid]);
                cout<<"4"<<endl;
                high = mid-1;
            }
        }
        return ans;
        
    }
};