class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]<=0) i++;
            else{
                int pos = nums[i]-1;
                if(pos<nums.size() && nums[pos]!=pos+1)//nums[i])
                {
                    swap(i,pos,nums);
                }
                else i++;
            }
        }
        for(int i = 0; i<nums.size();i++)
        {
            if(nums[i]!=i+1) return i+1;
        }
        return nums.size()+1;
    }
    void swap(int i, int j , vector<int>& nums){
        int k = nums[i];
        nums[i] = nums[j];
        nums[j] = k;
        return;
    }
};