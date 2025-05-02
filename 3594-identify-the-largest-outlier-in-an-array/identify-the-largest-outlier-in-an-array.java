class Solution {
    public int getLargestOutlier(int[] nums) {
        int total=0;
        int outlier= Integer.MIN_VALUE;
        Map<Integer,Integer> freq= new HashMap<>();
        for(int i:nums){
            total+=i;
               freq.put(i, freq.getOrDefault(i, 0) + 1);
        }
        for(int k : nums){
               int sum = total-k;
               if(sum%2!=0) continue;
               int required =sum/2;
               if (freq.containsKey(required)) {
                if (required == k) {
                    if (freq.get(required) > 1)    // need a second copy
                        outlier = Math.max(outlier, k);
                } else {
                    outlier = Math.max(outlier, k);
                }
            }

        }
        return outlier;
        
    }
}