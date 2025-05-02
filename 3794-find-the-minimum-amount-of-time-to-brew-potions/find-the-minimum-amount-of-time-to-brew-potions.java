class Solution {
    public long minTime(int[] skill, int[] mana) {
        long[] timeCheck = new long[skill.length];
        Arrays.fill(timeCheck,0L);
        for(int i=0;i<mana.length;i++){
            long previous = 0;
            for(int j=0;j<skill.length;j++)
            {
                if(j>0) previous = timeCheck[j-1];
                long time = Math.max(timeCheck[j],previous);
                timeCheck[j]=time + 1L*skill[j]*mana[i];
            }
            for(int j=skill.length-2;j>-1;j--){
                timeCheck[j] = timeCheck[j+1]- 1L*skill[j+1]*mana[i];
             }
        }
        return timeCheck[skill.length-1];
        
    }
}