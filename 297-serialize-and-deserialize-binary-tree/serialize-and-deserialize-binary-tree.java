/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root==null) return "N,";
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        StringBuilder sb = new StringBuilder();
        while(!q.isEmpty())
        {
            TreeNode temp = q.poll();
            if(temp==null){
                sb.append("N,");
            }
            else{
                sb.append(Integer.toString(temp.val));
                sb.append(",");
                q.offer(temp.left);
                q.offer(temp.right);
            }
        }
        System.out.println(sb.toString());
        return sb.toString();
        
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] temp = data.split(",");
        Queue<TreeNode> t = new LinkedList<>();
        TreeNode root = null;
        if(temp[0].equals("N")) return null;
        else{
           int k = Integer.parseInt(temp[0]);
           root = new TreeNode(k);
           t.offer(root);
        }
        int i=1;
        while(i<temp.length){
            TreeNode node = t.poll();
            if(!temp[i].equals("N"))
            {
                int k = Integer.parseInt(temp[i]);
                node.left = new TreeNode(k);
                t.offer(node.left);
            }
            i++;
            if(!temp[i].equals("N"))
            {
                int k = Integer.parseInt(temp[i]);
                node.right = new TreeNode(k);
                t.offer(node.right);
            }
            i++;
            
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));