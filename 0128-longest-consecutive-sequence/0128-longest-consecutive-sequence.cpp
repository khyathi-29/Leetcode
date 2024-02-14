class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> a;
        int ans =0;
        for(int i=0;i<nums.size();i++)
        {
            a.insert(nums[i]);
        }
        for(auto i = a.begin();i!=a.end();i++)
        {
            int x = *i;
            
            if(a.find(x-1)==a.end())
            {
                int count=1;
                while(a.find(x+1)!=a.end())
                {
                    x++;
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};