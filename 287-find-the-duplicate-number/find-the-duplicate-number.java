class Solution {
    public int findDuplicate(int[] nums) {
        int i = 0;
        while(i<nums.length)
        {
            int pos = nums[i]-1;
            if(nums[i]!=nums[pos])
            {
                swap(nums,i,pos);
            }
            else{
                i++;
            }
        }
        for(i=0;i<nums.length;i++)
        {
            if(nums[i]!=1+i) return nums[i];
        }
        return -1;
    }
    public void swap(int[] n,int i,int j)
    {
        int k = n[i];
        n[i]=n[j];
        n[j]=k;
        return;
    }
}