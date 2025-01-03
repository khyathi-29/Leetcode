class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a;
        vector<int> b;
        b = nums;
        sort(nums.begin(), nums.end());
        int i=0;
        int j= nums.size()-1;
        while(j>i)
        {
            if(nums[i]+nums[j]>target)
            {
                j = j-1;
            }
            else if (nums[i]+ nums[j]<target)
            {
                i=i+1;
            }
            else
            {
               
               break;
            }
        }

        for(int k=0; k< nums.size();k++)
        {
           
            if(nums[i]== b[k])
            {
                a.push_back(k);
                break;
            }
        }
        for(int k=nums.size()-1; k>-1;k--)
        {
           
            if(nums[j]== b[k])
            {
                a.push_back(k);
                break;
            }
        }
      return a;  
    }   
    
};
