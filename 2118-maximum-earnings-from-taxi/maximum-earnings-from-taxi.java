class Solution {
    public long maxTaxiEarnings(int n, int[][] times) {
        long[] ans = new long[times.length];
     Arrays.sort(times,(a,b)->{return a[0]-b[0];});
       return Helper(0,times,ans);
    }

    long Helper(int index, int[][] times,long[] ans){
        if(index==times.length) return 0;
        if(ans[index]!=0) return ans[index];
        long val = Helper(index+1,times,ans);//do not consider current job
        int j = index+1;
        while(j < times.length && times[index][1]>times[j][0]) j++;

        long tip = times[index][1]+times[index][2]-times[index][0];
        val = Math.max(val,Helper(j,times,ans)+tip);
        ans[index] = val;
        return val;
    }
}