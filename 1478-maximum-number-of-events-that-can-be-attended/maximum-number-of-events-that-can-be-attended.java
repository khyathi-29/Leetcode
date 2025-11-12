class Solution {
    public int maxEvents(int[][] events) {
        Arrays.sort(events, (a,b)->a[0]-b[0]);
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int i =0;
        int day = events[0][0];
        int attended =0;
        while(!pq.isEmpty() || i< events.length)
        {
            if(pq.isEmpty() && i < events.length) day = Math.max(day,events[i][0]);
            while(i < events.length && events[i][0]<= day)
            {
                pq.offer(events[i][1]);
                i++;
            }
            while(!pq.isEmpty() && pq.peek()<day) pq.poll();
            if (!pq.isEmpty()) {
            pq.poll();
            ++attended;
            ++day;
        }
        }
        return attended;
    }
}