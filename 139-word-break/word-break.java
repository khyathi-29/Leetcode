class TrieNode {
    boolean isWord;
    Map<Character, TrieNode> children;

    TrieNode() {
        this.children = new HashMap<>();
    }
}
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        TrieNode root = new TrieNode();
        for( String ss : wordDict){
             TrieNode curr = root;
            for (char c : ss.toCharArray()) {
                if (!curr.children.containsKey(c)) {
                    curr.children.put(c, new TrieNode());
                }

                curr = curr.children.get(c);
            }

            curr.isWord = true;
        }
        int n = s.length();
        boolean[] dp = new boolean[n+1];
        dp[0] = true;
        for(int i=1;i<=s.length();i++){
            if(dp[i-1]==true){
              TrieNode curr = root;
              for(int j = i;j<=s.length();j++)
              {
                char c = s.charAt(j-1);
                if(curr.children.containsKey(c)==false) break;
                curr = curr.children.get(c);
                if(curr.isWord==true) dp[j]=true;
              }
              
        }
        }
        return dp[n];
    }
}