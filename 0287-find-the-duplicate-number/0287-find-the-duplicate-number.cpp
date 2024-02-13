class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int add = nums.size();
        for( int i=0;i<nums.size();i++)
        {
            nums[nums[i]%add]=nums[nums[i]%add]+ add;
        }
        for( int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]/add;
            if(nums[i]>1){
                return i;
            }
        }
    
        return 0;
    }
};