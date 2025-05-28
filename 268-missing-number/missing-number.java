class Solution {
    public int missingNumber(int[] nums) {
        int i=0;
        while(i<nums.length)
        {
           int pos = nums[i];
           if(nums[i]<nums.length && nums[i]!=nums[pos])
           {
            swap(nums,i,pos);
           }
           else{
            i++;
           }
        }
        for(i=0;i<nums.length;i++)
        {
            if(nums[i]!=i) return i;
        }
        return nums.length;
    }
    public void swap(int[] nums,int i,int j)
    {
        int k = nums[i];
        nums[i]=nums[j];
        nums[j]=k;
    }
}