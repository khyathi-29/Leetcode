class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0;
        int right = 1;
        int steps=0;
        while(right<nums.size())
        {
            steps++;
            int val =0;
            for(int i=left;i<right && i<nums.size();i++)
            {
             val = max(val,nums[i]+i);
            }
            if(val>=nums.size()-1) return steps;
            left = right;
            right = val+1;
        }
        return steps;
    }
};