class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->Integer.compare(b[2], a[2]));
        for(int[] point: points){
            pq.add(new int[]{point[0],point[1],(point[0]*point[0])+(point[1]*point[1])});
            if(pq.size()>k) pq.poll();
        }
        int[][] ans = new int[pq.size()][2];
        int i=0;
        while(!pq.isEmpty())
        {
            int[] temp = pq.poll();
            ans[i][0]=temp[0];
            ans[i][1]=temp[1];
            i++;

        }
        return ans;
        
    }
}