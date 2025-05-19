class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int sum = nums[0]+nums[1]+nums[2];
        int ans = sum;
        int diff = Math.abs(sum - target);
        for(int i=0;i<nums.length-2;i++){
            int low = i+1;
            int high = nums.length-1;
            while(low<high)
            {
                int csum = nums[i]+nums[low]+nums[high];
                if(Math.abs(csum - target)<diff){
                    ans = csum;
                    diff = Math.abs(csum - target);
                }
                if(csum==target){
                    diff=0;
                    ans = csum;
                    break;
                }
                else if(csum>target){
                        high--;
                }
                else low++;
            }
        }
        return ans;
    }
}