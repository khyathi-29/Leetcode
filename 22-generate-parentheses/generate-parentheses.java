class Solution {
    public List<String> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        List<String> ans = new ArrayList<>();
        List<Character> temp = new ArrayList<>();
        Helper(open,close,n,ans,temp);
        return ans;
    }
    private void Helper(int open, int close, int n, List<String> ans, List<Character> temp){
        if(open == n && close == n){
            StringBuilder sb = new StringBuilder();
            for(char c : temp){
                sb.append(c);
            }
            ans.add(sb.toString());
                return;
        }
        if(open < n){
            temp.add('(');
            Helper(open+1,close,n,ans,temp);
            temp.remove(temp.size()-1);
        }
        if(close < open){
            temp.add(')');
            Helper(open,close+1,n,ans,temp);
            temp.remove(temp.size()-1);
        }

    }
}