class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int pivot = -1;
        for(int i = n-2;i>-1;i--)
        {
            if(nums[i]<nums[i+1])
            {
                pivot = i;
                break;
            }
        }
        if(pivot==-1) {
            reverse(nums,0,n-1);
            return;}
        for(int i = n-1;i>-1;i--)
        {
            if(nums[i]>nums[pivot]){
                int t = nums[i];
                nums[i] = nums[pivot];
                nums[pivot] = t;
                break;
            }
        }
        reverse(nums,pivot+1,n-1);
        return ;
    }
    public void reverse(int[] num, int i, int j)
    {
        while(i<j)
        {
            int t = num[i];
            num[i]=num[j];
            num[j]=t;
            i++;
            j--;
        }
    }
}