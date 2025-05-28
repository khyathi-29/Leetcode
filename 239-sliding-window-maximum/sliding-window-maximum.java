class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int s = nums.length-k;
        int[] ans = new int[s+1];
        Deque<Integer> q = new LinkedList<>();
        for(int i=0;i<nums.length;i++)
        {
            if(q.isEmpty()==false && q.peekFirst()<i+1-k) q.removeFirst();
            while(q.isEmpty()==false && nums[q.peekLast()]<nums[i]){
                q.removeLast();
            }
            q.offerLast(i);
            if(i>=k-1) ans[i+1-k]= nums[q.peekFirst()];
        }
        return ans;
    }
}