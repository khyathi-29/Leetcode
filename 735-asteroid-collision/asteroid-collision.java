class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st = new Stack<>();
        for(int i : asteroids)
        {
            if(i>0) st.push(i);
            else{
                while(!st.isEmpty() && st.peek()<Math.abs(i) && st.peek()>0) st.pop();
                if(!st.isEmpty() && st.peek()==Math.abs(i)) st.pop();
                else if(st.isEmpty() || st.peek()<0) st.push(i);
            }
        }
        int[] ans = new int[st.size()];
        int j =0;
        for(int i : st)
        {
          ans[j++]=i;
        }
        return ans;
    }
}