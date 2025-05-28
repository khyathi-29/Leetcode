class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int i=0;
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
            if(nums[i]!=i+1) ans.add(i+1);
        }
        return ans;
    }
    public void swap(int[] n,int i,int j)
    {
        int k = n[i];
        n[i]=n[j];
        n[j]=k;
        return;
    }
}