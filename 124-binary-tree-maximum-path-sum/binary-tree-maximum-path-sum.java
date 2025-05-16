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
    private int maxsum;
    public int maxPathSum(TreeNode root) {
        if(root == null) return 0;
        maxsum = root.val;
        maxPathSumHelper(root);
        return maxsum;
    }
    int maxPathSumHelper(TreeNode root)
    {
        if(root==null) return 0;

        int leftSum = Math.max(maxPathSumHelper(root.left),0);
        int rightSum = Math.max(maxPathSumHelper(root.right),0);

        maxsum = Math.max(leftSum + rightSum + root.val,maxsum);
        return root.val + Math.max(leftSum,rightSum);
    }
}