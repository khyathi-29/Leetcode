class Solution {
    public List<String> generateParenthesis(int n) {
        int openBrackets=0;
        int closeBrackets=0;
        List<Character> ls = new ArrayList<>();
        List<String> ans = new ArrayList<>();
        Helper(openBrackets,closeBrackets,ls,ans,n);
        return ans;
    }
    public void Helper(int op,int cl,List<Character> sb,List<String> ls,int n){
        if(op==n  && cl == n ){
           StringBuilder b = new StringBuilder();
           for (char c : sb) b.append(c);
           ls.add(b.toString());
        }
        if(op<n){
            sb.add('(');
            Helper(op+1,cl,sb,ls,n);
            sb.remove(sb.size()-1);
        }
        if(cl<op){
            sb.add(')');
            Helper(op,cl+1,sb,ls,n);
            sb.remove(sb.size()-1);
        }
    }
}