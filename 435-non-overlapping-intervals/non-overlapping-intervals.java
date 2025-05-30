class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals,(int[] a, int[] b)->{return a[0]-b[0];});
        int s = intervals[0][0];
        int e = intervals[0][1];
        int count = 0;
        for(int i=1;i<intervals.length;i++)
        {
             if(e>intervals[i][0])
             {
                e = Math.min(e,intervals[i][1]);
                count++;
             }
             else {
                s = intervals[i][0];
                e = intervals[i][1];
             }
        }
        return count;
    }
}