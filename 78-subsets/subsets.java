class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        Helper(0,nums,ans,temp);
        return ans;
    }
    public void Helper(int i, int[] nums, List<List<Integer>> ans, List<Integer> temp){
    if(i==nums.length){
        ans.add(new ArrayList<>(temp));
        return;
    }
     temp.add(nums[i]);
     Helper(i+1,nums,ans,temp);
     temp.remove(temp.size()-1);
     Helper(i+1,nums,ans,temp);
    }
}