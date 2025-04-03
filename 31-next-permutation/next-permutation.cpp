class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();
        for(int i= n-2;i>-1;i--){
            if(nums[i+1]>nums[i]){
                pivot = i;
                break;
            }
        }
       // cout<<pivot<<end;
        if(pivot==-1) sort(nums.begin(),nums.end());
        else{
            for(int i = n-1;i>pivot;i--){
                if(nums[pivot]<nums[i]){
                    int k = nums[pivot];
                    nums[pivot]=nums[i];
                    nums[i]=k;
                    break;
                }
            }
            sort(nums.begin()+pivot+1,nums.end());
        }
        return;
        
    }
};