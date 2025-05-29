class Solution {
    public int firstMissingPositive(int[] nums) {
        int i=0;
        while(i<nums.length)
        {
            int pos = nums[i]-1;
            if( nums[i]<=nums.length && nums[i]>=1 && nums[i]!=nums[pos])
            {
                 swap(nums,i,pos);
            }
            else{
                    i++;
            }
        }
        for(i=0;i<nums.length;i++)
        {
            if(nums[i]!=i+1) return i+1;
        }

        return nums.length+1;
    }
    public void swap(int[] nums,int i, int j)
    {
        int k = nums[i];
        nums[i]=nums[j];
        nums[j]=k;
    }
}