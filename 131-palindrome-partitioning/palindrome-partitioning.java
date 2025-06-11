class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        List<String> temp = new ArrayList<>();
        Helper(s,0,temp,ans);
        return ans;
    }
    void Helper(String s,int index,List<String> temp,List<List<String>> ans)
    {
        if(index==s.length()) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        for(int i = index+1;i<=s.length();i++)
        {
            String a = s.substring(index,i);
            if(isPalindrome(a)==true){
                temp.add(a);
                Helper(s,i,temp,ans);
                temp.remove(temp.size()-1);
            }
        }
    }
    boolean isPalindrome(String s)
    {
        int i = 0;
        int j = s.length()-1;
        while(i<j)
        {
            if(s.charAt(i)!=s.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }
}