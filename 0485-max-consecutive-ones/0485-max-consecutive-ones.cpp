class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maximum=0;
        int count=0;
        for(int num:nums)
        {
            if(num==1) count++;
            else count=0;
            maximum = max(maximum,count);
        }
        return maximum;
    }
};