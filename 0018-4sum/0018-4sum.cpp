class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int a=0;a<nums.size();a++)
        {
             if (a != 0 && nums[a] == nums[a - 1]) continue;
            long long int target1 = target-nums[a];
        for(int i=a+1;i<nums.size();i++)
        {
            if (i != a+1 && nums[i] == nums[i - 1]) continue;
            long long int target2 = target1-nums[i];
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                if(nums[j]+nums[k]>target2)
                {
                    k--;
                }
                else if(nums[j]+nums[k]<target2)
                {
                    j++;
                }
                else
                {
                    ans.push_back({nums[a],nums[i],nums[j],nums[k]});
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
        }
        return ans;
    
        
    }
};