class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int target = 0-nums[i];
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                if(nums[j]+nums[k]>target)
                {
                    k--;
                }
                else if(nums[j]+nums[k]<target)
                {
                    j++;
                }
                else
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    cout<<"i j k are"<<i<<j<<k<<endl;
                    while(j<k && nums[j]==nums[j+1])
                    {
                       j++;
                    }
                    while(j<k && nums[k]==nums[k-1])
                    {
                       k--;
                    }
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};