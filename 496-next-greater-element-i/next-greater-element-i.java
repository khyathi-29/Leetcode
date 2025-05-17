class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        
        Map<Integer, Integer> mp = new HashMap<>();
        int[] ans = new int[nums1.length];
        Arrays.fill(ans,-1);
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<nums2.length;i++){
            while(!st.isEmpty() && nums2[st.peek()]< nums2[i])
            {
                int k = st.pop();
                mp.put(nums2[k],nums2[i]);
            }
           if(st.isEmpty() || nums2[st.peek()]> nums2[i]){
            st.add(i);
           }
        }
        int j=0;
        for(int i: nums1){
            if(mp.containsKey(i)){
                ans[j]=mp.get(i);

            }
            else ans[j]=-1;
            j++;
        }
        return ans;
    }
}