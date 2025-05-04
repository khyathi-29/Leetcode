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
    public int maxPathSum(TreeNode root) {
        if(root==null) return 0;
       int[] maxval = new int[1];
       maxval[0] = root.val;
       maxPathSumHelper(root,maxval); 
       return maxval[0];
    }
    public int maxPathSumHelper(TreeNode root,int[] maxval){
        if(root==null) return 0;
        int lsum = Math.max(0,maxPathSumHelper(root.left,maxval));
        int rsum = Math.max(0,maxPathSumHelper(root.right,maxval));
        maxval[0] = Math.max(maxval[0],lsum+rsum+root.val);
        return root.val + Math.max(lsum,rsum);
    }
}