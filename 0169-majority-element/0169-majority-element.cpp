class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =1;
        int majority = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(count ==0)
            {
                majority=nums[i];
            }
            if(majority == nums[i])
            {
                count++;
            }
            if(majority != nums[i])
            {
                count--;
            }
        }
        return majority;
    }
};