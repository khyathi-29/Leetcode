class Solution {
    public boolean backspaceCompare(String s, String t) {
        int i = s.length()-1;
        int j = t.length()-1;
        int s_skips = 0;
        int t_skips = 0;
        while(i>-1 || j>-1){
            while(i>-1)
            {
                if(s.charAt(i)=='#'){
                    i--;
                    s_skips++;
                }
                else if(s_skips>0){
                    i--;
                    s_skips--;
                }
                else break;
            }
            while(j>-1)
            {
                if(t.charAt(j)=='#'){
                    j--;
                    t_skips++;
                }
                else if(t_skips>0){
                    j--;
                    t_skips--;
                }
                else break;
            }
            if(i>-1 && j>-1 && s.charAt(i)!=t.charAt(j)) return false;
            else if(i<0 && j<0) return true;
            else if(i<0 || j<0) return false;
            else {
                i--;
                j--;
            }
            System.out.println(i+" "+j);
        }
        return true;
        
    }
}