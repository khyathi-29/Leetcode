class Solution {
    public int leastInterval(char[] tasks, int n) {
        Queue<int[]> q = new LinkedList<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        int[] a = new int[26];
        for(int i=0;i<tasks.length;i++)
        {
           a[tasks[i]-'A']++;
        }
        for(int i: a){
            if(i>0){
                maxHeap.offer(i);
            }
        }
        int t=0;
        while(!q.isEmpty() || !maxHeap.isEmpty()){
             t++;
             if(!maxHeap.isEmpty()){
                
                int cnt = maxHeap.poll()-1;
                if(cnt>0){
                    q.offer(new int[]{cnt,t+n});
                }
             }
             else{
                t= q.peek()[1];
             }

             if (!q.isEmpty() && q.peek()[1] == t) {
                  maxHeap.add(q.poll()[0]);
                }
        }
        return t;

    }
}