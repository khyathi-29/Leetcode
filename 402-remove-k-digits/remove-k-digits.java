class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Integer> s = new Stack<>();
        char[] n = num.toCharArray();
        for( int i=0;i<num.length();i++)
        {
            while(!s.isEmpty() && n[s.peek()]>n[i] && k>0)
            {
                s.pop();
                k--;
            }
            s.add(i);
            if(s.size()==1 && n[s.peek()]=='0') s.pop();
        }
        while(k>0 && !s.isEmpty()) {
            s.pop();
            k--;
        }
        StringBuilder sb = new StringBuilder();
        for( int i : s)
        {
                 sb.append(n[i]);
        }
        if( sb.toString()=="" || sb.toString().charAt(0)=='0') return "0";
        return sb.toString();
    }
}