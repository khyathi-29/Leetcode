class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->(a[0]-b[0]));
        List<List<Integer>> ans = new ArrayList<>();
        pq.add(new int[]{nums1[0]+nums2[0],0,0});
        Set<String> s = new HashSet<>();
        String key = 0+"#"+0;
        s.add(key);
        while(!pq.isEmpty() && ans.size()<k)
        {
            int[] temp = pq.poll();
            int i = temp[1];
            int j = temp[2];
            ans.add(Arrays.asList(nums1[i],nums2[j]));
            String key1= (i+1)+"#"+j;
            String key2= i+"#"+(j+1);
            if(i+1<nums1.length && s.contains(key1)==false){
                pq.add(new int[]{nums1[i+1]+nums2[j],i+1,j});
                s.add(key1);
            } 
            if(j+1<nums2.length && s.contains(key2)==false) {
                pq.add(new int[]{nums1[i]+nums2[j+1],i,j+1});
                s.add(key2);
            
            }
        }
        return ans;
    }
}