class Solution {
    public void sortColors(int[] nums) {
        int i=0;//0 pointer
        int j= nums.length-1; // pointer for 2
        int k =0; // current pointer
        while(k<=j)
        {
            if(nums[k]==0)
            {
                swap(nums,k,i);
                i++;
                k++;
            }
            else if(nums[k]==2)
            {
                swap(nums,k,j);
                j--;
            }
            else{
                k++;
            }
        }
    }
    void swap(int[] nums,int i,int j)
    {
      int k = nums[i];
      nums[i] =nums[j];
      nums[j]=k;
    }
}