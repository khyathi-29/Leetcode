class Solution {
    public long getDescentPeriods(int[] prices) {
        int i=0;
        int j=0;
        long count=0;
        while(j<prices.length)
        {
            if(j!=0 && prices[j]+1!=prices[j-1])
            {
                i=j;
            }
            count+=j+1-i;
            j++;
        }
        return count;
    }
}