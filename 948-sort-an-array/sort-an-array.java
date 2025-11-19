class Solution {
    public int[] sortArray(int[] nums) {
        int low = 0;
        int high = nums.length-1;
        quickSort(nums,low,high);
        return nums;
    }
    public void quickSort(int[] nums, int l, int h)
    {
           if(l>=h) return;
            int[] partition = Helper(nums,l,h);
            quickSort(nums,l,partition[0]-1);
            quickSort(nums,partition[1]+1,h);
    }
    int[] Helper(int[] nums, int l, int h)
    {
       /* int partition = nums[h];
        for(int i=l;i<h;i++)
        {
            if(nums[i]<partition){
                swap(nums,l,i);
                l++;
            }
        }
        swap(nums,l,h);
        return l;*/
         int pivot = nums[h];
        int lt = l;      // boundary for < pivot
        int i = l;       // current index
        int gt = h;      // boundary for > pivot

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums, lt, i);
                lt++;
                i++;
            } else if (nums[i] > pivot) {
                swap(nums, i, gt);
                gt--;
                // don't i++ here, need to check nums[i] after swap
            } else {
                i++; // nums[i] == pivot
            }
        }
        return new int[]{lt, gt};
    }
    void swap(int[] nums, int i,int j){
        int k = nums[i];
        nums[i]=nums[j];
        nums[j]=k;
        return;
    }
}