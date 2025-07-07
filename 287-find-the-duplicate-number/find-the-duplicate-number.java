class Solution {
    // the one already not in correct position and if there exists one element in correct position we can just return it;
    public int findDuplicate(int[] nums) {
        int i = 0;
        while(i<nums.length)
        {
            if(nums[i]!=i){
            int pos = nums[i];
            if(nums[i]!=nums[pos])
            {
                swap(nums,i,pos);
            }
            else{
                return nums[i];
            }
          }
          else i++;
        }
        for(i=0;i<nums.length;i++)
        {
            if(nums[i]!=1) return nums[i];
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