class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        Helper(0,nums,ans,temp);
        return ans;

    }
    public void Helper(int index,int[] nums,List<List<Integer>> ans,List<Integer> temp)
    {
        ans.add(new ArrayList<>(temp));
        if(index== nums.length)
        {
            return;
        }
        for(int i = index ; i< nums.length ; i++)
        {
            if(i!=index && nums[i]==nums[i-1]) continue;
            temp.add(nums[i]);
            Helper(i+1,nums,ans,temp);
            temp.remove(temp.size()-1);
        }
        
    }
}