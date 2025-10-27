class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        List<Character> temp = new ArrayList();
        Helper( n , 0, 0, ans,temp);
        return ans;
    }
    public void Helper(int n, int leftP, int rightP, List<String> ans, List<Character>temp){
        if(leftP==rightP && n==leftP) {
            StringBuilder sb = new StringBuilder("");
            for(char c : temp) sb.append(c);
            ans.add(sb.toString());
            return;
        }
        if(leftP<n)
        {
            temp.add('(');
            Helper(n, leftP+1,rightP,ans,temp);
            temp.remove(temp.size()-1);
        }
        if(rightP<leftP)
        {
            temp.add(')');
            Helper(n, leftP,rightP+1,ans,temp);
            temp.remove(temp.size()-1);
        }
        return;
    }
}