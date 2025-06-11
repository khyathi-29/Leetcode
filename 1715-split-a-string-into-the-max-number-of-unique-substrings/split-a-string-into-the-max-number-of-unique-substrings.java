class Solution {
    public int maxUniqueSplit(String s) {
        int[] ans = new int[1];
        ans[0]= 1;
        Set<String> se = new HashSet<>();
        Helper(0,0,s,se,ans);
        return ans[0];
        
    }
    void Helper(int index, int split, String s,Set<String> se,int[] ans)
    {
        if(index==s.length()){
            ans[0]= Math.max(ans[0],split);
            return;
        }
        for(int i= index+1;i<=s.length();i++){
            String a = s.substring(index,i);
            if(se.contains(a)==false){
                se.add(a);
                Helper(i,split+1,s,se,ans);
                se.remove(a);
            }
        }
    }
}