class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer,Integer> m = new HashMap<>();
        m.put(0,-1);
        int sum=0, maxLength = 0;
        for(int i=0;i<nums.length;i++)
        {
            sum += (nums[i]==0)? -1:1;
            System.out.println(sum);
            if(m.get(sum)!=null) maxLength = Math.max(maxLength,i-m.get(sum));
            if(m.get(sum)==null) m.put(sum,i);
        }
        
        return maxLength;
    }
}