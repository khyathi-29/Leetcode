class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new LinkedList<>();
        int n = nums.length-k+1;
        int[] ans = new int[n];
        int i = 0;
        for(int j = 0; j<nums.length;j++)
        {
            while(!dq.isEmpty() && nums[dq.peekLast()]<nums[j])
            {
                System.out.println(dq.pollLast());
            }
            dq.addLast(j);
            if(dq.peekFirst()<=j-k) dq.pollFirst();
            if(j+1>=k){
                ans[i]= nums[dq.peekFirst()];
                i++;
            }
            
        }
        return ans;
    }
}