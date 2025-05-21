class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        Arrays.sort(candidates);
        combinationSum(0,ans,temp,candidates,target);
        return ans;
    }
    void combinationSum(int index, List<List<Integer>> ans,List<Integer> temp,int[] nums, int target)
    {
          if(target==0){
             ans.add(new ArrayList(temp));
             return;
          }
          if(index==nums.length) return;
          for(int i=index ;i<nums.length;i++){
          if(i>index && nums[i]==nums[i-1]) continue;
          if(nums[i]<=target){
            temp.add(nums[i]);
            combinationSum(i+1,ans,temp,nums,target-nums[i]);
            temp.remove(temp.size()-1);
          }
         }
          
    }
}