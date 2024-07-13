class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int longest=0;
        for(int num:nums)
        {
            s.insert(num);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]-1)==s.end())
            {
                int count = 1;
                int val = nums[i]+1;
                while(s.find(val)!=s.end())
                {
                    count++;
                    val++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};