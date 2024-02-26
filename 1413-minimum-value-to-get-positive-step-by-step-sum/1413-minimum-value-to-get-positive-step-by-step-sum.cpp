class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int current_sum=0;
        int min_sum= INT_MAX;
        for(int i=0; i<nums.size();i++)
        {
            current_sum+=nums[i];
            min_sum = min(current_sum,min_sum);
        }
        if(min_sum>=1)
        {
             return 1;
        }
        return abs(min_sum)+1;
    }
};