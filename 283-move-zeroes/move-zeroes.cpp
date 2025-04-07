class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int numberNonZero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                int k = nums[numberNonZero];
                nums[numberNonZero] = nums[i];
                nums[i]=k;
                numberNonZero++;
            }
        }

       return; 
    }
};