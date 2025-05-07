class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        if(digits.length()==0) return ans;
        String[] map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<Character> temp = new ArrayList<>();
        Helper(0,digits,map,temp,ans);
        return ans;
    }
    public void Helper(int digit, String digits,String[] map,List<Character> temp,List<String> ans)
    {
        if(digit==digits.length()){
            StringBuilder sb = new StringBuilder();
            for(char c: temp){
                sb.append(c);
            }
            ans.add(sb.toString());
            return;
        }
        int num = digits.charAt(digit)-'0';
        for( char c : map[num].toCharArray())
        {
            temp.add(c);
            Helper(digit+1,digits,map,temp,ans);
            temp.remove(temp.size()-1);
        }
    }
}