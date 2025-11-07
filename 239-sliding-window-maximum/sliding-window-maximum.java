class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new LinkedList<>();
        int[] ans = new int[nums.length+1-k];
        int i =0;
        for(int j = 0 ; j< nums.length ; j++)
        {
              while(dq.isEmpty()==false && nums[dq.peekLast()]<=nums[j]){
                    dq.pollLast();
              }
              dq.offerLast(j);
              if(dq.peekFirst()<=j-k) dq.pollFirst();
              if(j+1>=k){
                ans[i]= nums[dq.peekFirst()];
                i++;
              }
        }
        return ans;

    }
}