class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        int i= 0;
        List<Integer> ans = new ArrayList<>();
        while(i<nums.length)
        {
         int pos = nums[i]-1;
         if(nums[i]!=nums[pos])
         {
            swap(nums,i,pos);
         }
         else i++;
        }
        for(i=0;i<nums.length;i++)
        {
            if(nums[i]!=i+1) ans.add(nums[i]);
        }
        return ans;
    }
    public void swap(int[] nums,int i, int j)
    {
        int k = nums[i];
        nums[i]=nums[j];
        nums[j]=k;
        return;
    }
}