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
    public boolean isValidBST(TreeNode root) {
        long max = Long.MAX_VALUE;
        long min = Long.MIN_VALUE;
        return Helper(root,min,max);
        
    }
    public boolean Helper(TreeNode root, long min, long max)
    {
         if(root==null) return true;
         if(root.val<=min || root.val>=max) return false;
         else return (Helper(root.left,min,root.val) && Helper(root.right,root.val,max));
    }
}