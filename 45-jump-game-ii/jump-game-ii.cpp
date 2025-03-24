class Solution {
public:
    int jump(vector<int>& nums) {
        // to store the range of values we can traverse from a node in case of first index 
        //it's 1st to 2nd as in next ieration itwould be from 3 to 4
        int left=0;
        int right=0;
        int steps=0;
        int maxreach =0;
        while(left<nums.size()){
            for(int i=left;i<=right;i++){
                if(i==nums.size()-1) return steps;
                maxreach = max(maxreach,i+nums[i]);
            }
            steps++;
            left = right+1;
            right = maxreach;
        }
        return steps;
        
    }
};