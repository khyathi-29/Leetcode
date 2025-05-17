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
    public int minDepth(TreeNode root) {
        if(root==null) return 0;
        int lhs = minDepth(root.left);
        int rhs = minDepth(root.right);
        if(root.left==null || root.right==null)
        {
            return 1 + Math.max(lhs,rhs); //because the if there is no left child or 
            //no right child we shouldn't consider that side
        }
        return 1+ Math.min(lhs,rhs);
        
    }
}