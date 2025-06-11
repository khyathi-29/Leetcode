class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->(a[0]-b[0]));
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=0;i<Math.min(nums1.length,k);i++)
        {
           pq.add(new int[]{nums1[i]+nums2[0],i,0});
        }
        while(!pq.isEmpty() && ans.size()<k)
        {
            int[] temp = pq.poll();
            int i = temp[1];
            int j = temp[2];
            ans.add(Arrays.asList(nums1[i],nums2[j]));
            if(j+1 < nums2.length) pq.add(new int[]{nums1[i]+nums2[j+1],i,j+1});
        }
        return ans;
    }
}