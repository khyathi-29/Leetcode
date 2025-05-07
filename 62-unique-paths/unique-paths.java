class Solution {
    public int uniquePaths(int m, int n) {
        int N = m+n-2;
        int R = Math.min(m,n)-1;
        long ans = 1;
        for(int i=0;i<R;i++)
        {
            ans = ans*(N-i)/(i+1);
        }
        return (int)ans;
    }
}