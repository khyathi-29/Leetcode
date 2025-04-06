class Solution {
public:
// start = 0 and end =0;
// if number is 0 flips --
// once flips become po
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int zeroCount = 0;
        int maxSize = 0;

        while(end<nums.size()){
            if(nums[end]==0) zeroCount++;
            while(zeroCount>k){
                if(nums[start]==0) zeroCount--;
                start++;
            }
                
            maxSize = max(maxSize,end-start+1);
            end++;
        }
        return maxSize;
        
    }
};