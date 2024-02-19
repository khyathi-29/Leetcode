class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxv =0;
        int current = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                current++;
            }
            else
            {
                current = 0;
            }
            maxv = max(current,maxv);
        }
       return maxv; 
    }
};