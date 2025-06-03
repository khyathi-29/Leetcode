/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        Queue<Integer> qq = new LinkedList<>();
        if(root==null) return 0;
        int width = 0;
        q.offer(root);
        qq.offer(0);
        while(q.isEmpty()==false)
        {
            int s = q.size();
            int lowest_index = qq.peek();
            int start  =0;
            int end = 0;
            for(int i = 0;i<s;i++)
            {
                int index = qq.poll()-lowest_index;
                TreeNode n = q.poll();
                if(i==0) start = index;
                if(i==s-1) end = index;
                if(n.left!=null){
                    qq.offer(2*index+1);
                    q.offer(n.left);
                }
                if(n.right!=null)
                {
                     qq.offer(2*index+2);
                    q.offer(n.right);
                }
            }
            width = Math.max(width,end-start+1);
        }
         return width;
        
    }
}