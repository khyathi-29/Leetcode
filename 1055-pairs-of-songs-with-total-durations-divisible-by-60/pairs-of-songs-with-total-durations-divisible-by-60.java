class Solution {
    public int numPairsDivisibleBy60(int[] time) {
      int[] songMap = new int[60];
      int cnt = 0;
      for(int i : time)
      {
        int val = i%60;
        if(val==0) cnt +=songMap[0];
        else cnt += songMap[60-val];
        songMap[val]++;
      }
      return cnt;
    }
}