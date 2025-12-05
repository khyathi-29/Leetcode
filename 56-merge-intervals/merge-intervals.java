class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> l = new ArrayList<>();
        Arrays.sort(intervals,(a,b)->{return a[0]-b[0];});
        int n = intervals.length;
        int end = intervals[0][1];
        int start = intervals[0][0];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<= end){
                end = Math.max(end,intervals[i][1]);
            }
            else{
                l.add(new int[]{start,end});
                start = intervals[i][0];
                end =intervals[i][1];
            }
        }
        l.add(new int[]{start,end});
        return l.toArray(new int[l.size()][]);
    }
}