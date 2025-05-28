class Solution {
    public List<List<Integer>> combine(int n, int k) {
       int[] visited = new int[n+1];
       List<List<Integer>> ans = new ArrayList<>();
       List<Integer> temp = new ArrayList<>();
       Helper(1,n,k,ans,temp,visited);
       return ans;
    }
    public void Helper(int j,int n , int k, List<List<Integer>> ans, List<Integer> temp,int[] visited)
    {
        if(k==temp.size())
        {
            ans.add(new ArrayList(temp));
            return;
        }
        for(int i=j; i<=n;i++)
        {
            if(visited[i]==0)
            {
            temp.add(i);
            visited[i]=1;
            Helper(i+1,n,k,ans,temp,visited);
            visited[i]=0;
            temp.remove(temp.size()-1);
            }
        }
    }
}