class Solution {
    public int largestRectangleArea(int[] heights) {
        int maxArea = 0;
        Stack<Integer> s = new Stack<>();
        for(int i=0;i<=heights.length;i++)
        {
            while(!s.isEmpty() && (i==heights.length || heights[s.peek()]>heights[i])){
                int h = heights[s.peek()];
                s.pop();
                int width = (s.isEmpty())? i :i-1- s.peek();
                maxArea = Math.max(maxArea,h*width);
            }
            s.push(i);
        }
         return maxArea;
    }
}