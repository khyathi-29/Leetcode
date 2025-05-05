class Solution {
    // do not use nums as it may containe repeated elements
    public int longestConsecutive(int[] nums) {
        Set<Integer> s = new HashSet<>();
        int ans =0;
        for(int i: nums) s.add(i);
        for(int i : s){
            if(s.contains(i+1)==false){
                 int count = 0;
                while(s.contains(i)!=false){
                    count++;
                    i--;
                }
                ans = Math.max(count,ans);
            }
        }
        return ans;
    }
}