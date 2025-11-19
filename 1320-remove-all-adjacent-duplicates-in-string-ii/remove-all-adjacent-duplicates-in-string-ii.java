class Solution {
    public String removeDuplicates(String s, int k) {
        StringBuilder sb = new StringBuilder("");
        Stack<int[]> st = new Stack<>();// keeps the previous index,count
        for(int i =0 ;i < s.length();i++)
        {
            if(st.isEmpty() || s.charAt(st.peek()[0])!=s.charAt(i) )
            {
                st.add(new int[]{i,1});
            }
            else{
                
                st.add(new int[]{i,st.pop()[1]+1});
                if(st.peek()[1]==k) st.pop();
            }
        }
        for(int[] temp: st)
        {
            System.out.println(temp[0]+" "+temp[1]);
            int count = temp[1];
            while(count>0){
                sb.append(s.charAt(temp[0]));
                count--;
            }
        }

        return sb.toString();
    }
}