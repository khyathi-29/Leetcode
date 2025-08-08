class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]<0) i++;
            else{
            int pos = nums[i]-1;
            if( nums[i]<=nums.size() && nums[i]>=1 && nums[i]!=nums[pos])
            {
                 swap(nums,i,pos);
            }
            else{
                    i++;
            }
            }
        }
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1) return i+1;
        }

        return nums.size()+1;
    }
    void swap(vector<int>& ans, int i, int j)
    {
        int k = ans[i];
        ans[i] = ans[j];
        ans[j]=k;
    }
};