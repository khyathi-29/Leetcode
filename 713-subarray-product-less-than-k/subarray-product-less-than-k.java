class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int i=0;
        int j=0;
        int p =1;
        int count =0;
        while(j<nums.length)
        {
            p = p*nums[j];
            while(p>=k && i<=j)
            {
               p =p/nums[i];
               i++;
            }
            count+=j+1-i;
            j++;
        }
        return count;
    }
}