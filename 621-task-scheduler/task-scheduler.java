class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] f = new int[26];
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        Queue<int[]> q = new LinkedList<>();
        for(char c : tasks){
            f[c-'A']++;
        }
        for(int i=0;i<26;i++)
        {
            if(f[i]>0) maxHeap.offer(f[i]);
        }
        int time = 0;
        while(!maxHeap.isEmpty() || !q.isEmpty())
        {
            time++;
            if(!maxHeap.isEmpty())
            {
                int freq = maxHeap.poll();
                if(freq>1) q.offer(new int[]{freq-1,time+n});
            }
            else{
                time = q.peek()[1];
            }
            if(!q.isEmpty() && time==q.peek()[1]){
                maxHeap.offer(q.poll()[0]);
            }
            
        }
        return time;
    }
}