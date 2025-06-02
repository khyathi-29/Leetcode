class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> ans = new ArrayList<>();
        int i=0;
        while(i<intervals.length)
        {
            if(intervals[i][1]< newInterval[0]){
                int[] temp = new int[2];
                temp[0]=intervals[i][0];
                temp[1]=intervals[i][1];
                ans.add(temp);
                i++;
            }
            else break;
        }
        int start = newInterval[0];
        int end = newInterval[1];
        for(int j = i; j<intervals.length; j++)
        {
            if(intervals[j][0] <= end)
            {
                start = Math.min(intervals[j][0],start); 
                end = Math.max(intervals[j][1],end);
            }
            else {
                ans.add(new int[]{start,end});
                start = intervals[j][0];
                end = intervals[j][1];
            }
        }
        ans.add(new int[]{start,end});
        return ans.toArray(new int[ans.size()][]);
    }
}