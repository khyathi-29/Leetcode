class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i =0;
        while(i<nums.size())
        {
            if(nums[i]!=i)
            {
                int pos = nums[i];
                if(nums[pos]!=nums[i])
                {
                    swap(nums,i,pos);
                }
                else return nums[i];
                // since already exists in correct position then the number is duplicate
            }
            else {
                i++;
            }
        }
        return -1;
    }
    void swap(vector<int>& nums, int i, int j)
    {
        int k = nums[i];
        nums[i]=nums[j];
        nums[j]=k;
        return;
    }
};