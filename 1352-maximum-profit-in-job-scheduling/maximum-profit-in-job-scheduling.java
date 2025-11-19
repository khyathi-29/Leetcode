class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
    int n = startTime.length;
    int[][] times = new int[n][3];
    int[] ans = new int[n];
    for(int i=0;i<n;i++){
        times[i][0] = startTime[i];
        times[i][1] = endTime[i];
        times[i][2] = profit[i];
    }
     Arrays.sort(times,(a,b)->{return a[0]-b[0];});
       return Helper(0,times,ans);
    }
    int Helper(int index, int[][] times,int[] ans){
        if(index==times.length) return 0;
        if(ans[index]!=0) return ans[index];
        int val = Helper(index+1,times,ans);//do not consider current job
        int j = index+1;
        while(j< times.length && times[index][1]>times[j][0]) j++;
        val = Math.max(val,Helper(j,times,ans)+times[index][2]);
        ans[index] = val;
        return val;
    }
}