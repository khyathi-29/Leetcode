class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {

       List<List<Integer>> ans = new ArrayList<>();
       List<Integer> temp = new ArrayList<>();
       Helper(0,k,n,0,ans,temp);
       return ans; 
    }
    public void Helper(int i, int k, int n,int sum, List<List<Integer>> ans, List<Integer> temp){
        if(temp.size()==k){
            if(sum==n) ans.add(new ArrayList(temp));
            return;
        }
        for(int j=i+1;j<10;j++)
        {
            if(sum + j > n) break;
                temp.add(j);
                Helper(j,k,n,sum+j,ans,temp);
                temp.remove(temp.size()-1);
        }
    }
}