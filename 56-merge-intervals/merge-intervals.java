class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals,(a,b)->{ return a[0]-b[0];});
        List<int[]> temp = new ArrayList<>();
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1;i<intervals.length;i++)
        {
            if(end>= intervals[i][0])
            {
                end = Math.max(end,intervals[i][1]);
            }
            else{
                temp.add(new int[]{start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        temp.add(new int[]{start,end});
        return temp.toArray(new int[temp.size()][]);
    }
}