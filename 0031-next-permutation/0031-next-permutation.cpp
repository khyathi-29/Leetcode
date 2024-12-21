class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;

        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                pivot = i-1;
                break;
            }
        }
        if(pivot == -1)
        {
            sort(nums.begin(),nums.end());
        }
        else
        {
        for(int i= nums.size()-1;i>pivot;i--)
        {
            if(nums[i]>nums[pivot])
            {
                
                int b = nums[i];
                nums[i] = nums[pivot];
                nums[pivot]=b;
                break;
                
            }
        }
        sort(nums.begin()+pivot+1,nums.end());
        }
        
    }
};