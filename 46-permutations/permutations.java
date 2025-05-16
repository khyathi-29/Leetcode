class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        Helper(0,nums,ans);
        return ans;
    }
    public void Helper(int i, int[] nums, List<List<Integer>> ans)
    {
        if(i==nums.length){
            List<Integer> temp = new ArrayList<>();
            for(int k:nums) temp.add(k);
            ans.add(temp);
            return;
        }
        for(int j=i; j<nums.length ; j++){
            int a = nums[j];
            nums[j]=nums[i];
            nums[i]=a;
            Helper(i+1,nums,ans);
            a = nums[j];
            nums[j]=nums[i];
            nums[i]=a;

        }
     return;
    }
}