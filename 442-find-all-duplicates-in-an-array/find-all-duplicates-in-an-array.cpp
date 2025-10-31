class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0;
        vector<int> ans;
        while(i<nums.size())
        {
            
                int pos = nums[i]-1;
                if(nums[pos]!= nums[i])
                {
                    int temp = nums[i];
                    nums[i]= nums[pos];
                    nums[pos] = temp;
                }
           
                 else i++;
        }
        for( int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1) ans.push_back(nums[i]);
        }
        return ans;
    
    }
};