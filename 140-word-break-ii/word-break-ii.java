class TrieNode {
    boolean isWord;
    Map<Character, TrieNode> children;

    TrieNode() {
        this.children = new HashMap<>();
    }
}     
class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
         List<String> temp = new ArrayList<>();
         List<String> ans = new ArrayList<>();
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
         DFS(s,0,root,temp,ans);
         return ans;
    }
    public void DFS(String s,int index,TrieNode root,List<String> temp, List<String> ans)
    {
        if(index == s.length())
        {
            StringBuilder sb = new StringBuilder("");
            for(int i= 0 ;i<temp.size()-1;i++)
            {
                  sb.append(temp.get(i)).append(" ");
            }
            sb.append(temp.get(temp.size()-1));
            ans.add(sb.toString());
            return;
        }
       TrieNode current = root;
        for(int j = index ; j< s.length();j++)
        {
            char c = s.charAt(j);
            current = current.children.get(c);
            if(current == null) break;
            if(current.isWord==true){
                String prefix = s.substring(index,j+1);
                temp.add(prefix);
                DFS(s,j+1,root,temp,ans);
                temp.remove(temp.size()-1);
            }
        }

        return;
    }
}