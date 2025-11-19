class Solution {
    public String reverseParentheses(String s) {
        int[] pair = new int[s.length()];
        Stack<Integer> st = new Stack<>();
        StringBuilder sb = new StringBuilder("");
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='(') st.push(i);
            else if(s.charAt(i)==')'){
                int start = st.pop();
                pair[start] = i;
                pair[i] = start;
            }
            else pair[i]=-1;
        }
        int dir = 1;
        for(int i =0;i<s.length();i=i+dir)
        {
            if(s.charAt(i)=='(' || s.charAt(i)==')'){
                dir = -dir;
                i = pair[i];
                System.out.println(i+" "+dir);
            }
            else sb.append(s.charAt(i));
            
        }
        return sb.toString();
    }
}