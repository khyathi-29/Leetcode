class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int k = nums.size();
       for(int i=0;i<nums.size();i++)
       {
        nums[nums[i]%k]=nums[nums[i]%k]+k; 
       }
       for(int i=0;i<nums.size();i++)
       {
          nums[i]=nums[i]/k; 
          if(nums[i]>1)
          {
            return i;
          }
       }
       return -1;
    }
};