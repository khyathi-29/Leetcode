class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int tsum = nums.size()*(nums.size()+1);
        tsum=tsum/2;
        return tsum-sum;
    }
};