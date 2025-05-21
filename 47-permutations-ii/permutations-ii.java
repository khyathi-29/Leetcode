class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];
        List<Integer> temp = new ArrayList<>();
        Helper(0,ans,temp,visited,nums);
        return ans;
    }
    private void Helper(int j ,List<List<Integer>> ans,List<Integer> temp,boolean[] visited,int[] nums)
    {
              if(j==nums.length){
                ans.add(new ArrayList(temp));
                return;
              }
              
              for( int i=0;i<nums.length;i++){
                if(visited[i]== true) continue;
                if(i>0 && nums[i]==nums[i-1] && visited[i-1]==true) continue;
                visited[i] = true;
                temp.add(nums[i]);
                Helper(j+1,ans,temp,visited,nums);
                temp.remove(temp.size()-1);
                visited[i]= false;

              }
    }
}