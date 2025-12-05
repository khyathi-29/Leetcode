class Solution {
    public String simplifyPath(String path) {
        String[] paths = path.split("/");
        Stack<String> st = new Stack<>();
        for(String s : paths){
            if(s.equals(".") || s.equals("")) continue;
            else if(s.equals("..")){
                if(!st.isEmpty()) st.pop();
            }
            else st.add(s);
        }
        StringBuilder sb = new StringBuilder("");
        if(st.isEmpty()) return "/";
        for(String i : st){
            sb.append("/").append(i);
        }
        return sb.toString();
    }
}