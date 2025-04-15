class Solution {
    vector<int> num ;
public:
    Solution(vector<int>& nums) {
        num = nums;
    }
    
    int pick(int target) {
        int count = 0;
        int index=-1;
        for(int i=0;i<num.size();i++){
            if(num[i]==target){
                 count++;
                if(rand()%count==0) index=i;
            }
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */