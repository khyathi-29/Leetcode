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
    int maxVal ;
    public int maxPathSum(TreeNode root) {
        if(root == null) return 0;
        maxVal = root.val;
        Helper(root);
        return maxVal;
    }
    int Helper(TreeNode root)
    {
        if(root==null) return 0;
        int leftPath = Math.max(Helper(root.left),0);
        int rightPath = Math.max(Helper(root.right),0);
        maxVal = Math.max(leftPath+rightPath+root.val,maxVal);
        return root.val + Math.max(leftPath,rightPath);
    }
}