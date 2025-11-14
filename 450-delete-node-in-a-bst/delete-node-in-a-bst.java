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
    public TreeNode deleteNode(TreeNode root, int key) {
        TreeNode current = root;
        TreeNode parent = null;
        while(current!=null && current.val!=key)
        {
            parent = current;
            if(current.val > key) current = current.left;
            else current = current.right;
        }
        TreeNode child =null;
        if(current==null) return root;
        else if( current.left ==null) child = current.right;
        else if( current.right==null) child = current.left;
        else{
            TreeNode pred = current.left;
            TreeNode temp = current.right;
            child = temp;
            while(temp.left!=null)
            {
                temp = temp.left;
            }
            temp.left = pred;
        }
        if(parent==null) return child;
        if(parent.left==current) parent.left = child;
        else parent.right = child;
        return root;
    }
    
}