class Solution {
    public String convert(String s, int numRows) {
        int addAfter = 2*(numRows-1);
        if(numRows==1 || numRows>=s.length()) return s;
        StringBuilder sb = new StringBuilder("");
        for(int r=0; r<numRows ; r++)
        {
            for(int j =r; j<s.length();j=j+addAfter)
            {
                  sb.append(s.charAt(j));
                  int diag = j+addAfter-2*r;
                  if( r!=0 && r!=numRows-1 && diag<s.length()){
                    sb.append(s.charAt(j+addAfter-2*r));
                  }
            }
        }
        return sb.toString();
    }
}