class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] ans = new int[temperatures.length];
        Stack<Integer> q = new Stack<>();
        q.add(0);
        for(int i=1;i<temperatures.length;i++){
            while(q.isEmpty()!=true && temperatures[q.peek()]<temperatures[i]){
                int t = q.pop();
                ans[t] = i-t;
            }
            q.add(i);
        }
        return ans;
    }
}