class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer,Integer> mp = new HashMap<>();
        int left = 0 ;
        int right = 0;
        int maxLen = 0;
        while(right < fruits.length)
        {
            mp.put(fruits[right],mp.getOrDefault(fruits[right],0)+1);
            while(mp.size()>2 && left<right)
            {
                mp.put(fruits[left],mp.get(fruits[left])-1);
                if(mp.get(fruits[left])==0)
                {
                    mp.remove(fruits[left]);
                }
                left++;
            }
            maxLen = Math.max(maxLen,right+1-left);
            right++;
             
        }
    return maxLen;
    }
}