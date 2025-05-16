class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        List<int[]> ans = new ArrayList<>();
        int i = 0;
        int n = firstList.length;
        int j = 0;
        int m = secondList.length;
        while(i<n && j<m){
            if(firstList[i][0]<=secondList[j][1] && firstList[i][1]>=secondList[j][0])
            {
                ans.add(new int[]{Math.max(firstList[i][0],secondList[j][0]),Math.min(firstList[i][1],secondList[j][1])});
            }
            if(firstList[i][1]<secondList[j][1])
            {
                i++;
            }
            else j++;
        }

       int[][] result = ans.toArray(new int[ans.size()][]);
       return result;
        
    }
}