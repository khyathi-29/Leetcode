class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        int len = asteroids.length;
        Stack<Integer> st = new Stack<>();
        for(int i : asteroids)
        {
            if(i>0){
                      st.push(i);
            }
            else{
                while(!st.isEmpty() && st.peek()>0 && st.peek()<Math.abs(i)){
                    st.pop();
                }
                if(!st.isEmpty() && st.peek()==Math.abs(i)){
                    st.pop();
                }
                else if(st.isEmpty() || st.peek()<0){
                    //if stack is empty or its top element is less than 0
                    st.push(i);
                }
            }
        }
        int[] ans = new int[st.size()];
        for(int i= st.size()-1;i>-1;i--){
            ans[i]=st.pop();
        }
        return ans;
    }
}