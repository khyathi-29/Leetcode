class Solution {
    public int[] fullBloomFlowers(int[][] flowers, int[] people) {
        int[] start = new int[flowers.length];
        int[] end = new int[flowers.length];
        int[] ans = new int[people.length];
        int i=0;
        // here we need to add +1 to end time because if it ends in corretly at p[i]
        // then we need to consider it as bloomed and not subtract it assuming it as
        // not in full bloom
        // return ans + 1 and initilize ans = -1;
        for(int[] temp : flowers)
        {
            start[i]=temp[0];
            end[i]=temp[1]+1;
            i++;
        }
        Arrays.sort(start);
        Arrays.sort(end);
        for( i=0;i<people.length;i++)
        {
            int a = Helper(people[i],start);
            int b = Helper(people[i],end);
            //System.out.println(" a " + a + " b " + b);
            ans[i] = a-b;
        }
        return ans;
    }
    public int Helper(int val,int[] start)
    {
        int low = 0;
        int ans = -1;
        int high = start.length-1;
        // System.out.println("ppppppppp");
        while(low <= high)
        {
            int mid = low + (high-low)/2;
             //System.out.println(mid + " mid is " + start[mid]);
            if( start[mid]<= val)
            {
                ans = Math.max(ans,mid);
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans+1;
    }
}