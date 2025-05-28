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
    public int kthSmallest(TreeNode root, int k) {
      int[]  count = new int[1];
      return Helper(root,k,count);
        
    }
    public int Helper(TreeNode root, int k,int[] count)
    {
        if(root==null) return -1;
        int t = Helper(root.left,k,count);
        if(t!=-1) return t;
        count[0]++;
        if(count[0]==k) return root.val;
        t = Helper(root.right,k,count);
        if(t!=-1) return t;
        return -1;
    }
}