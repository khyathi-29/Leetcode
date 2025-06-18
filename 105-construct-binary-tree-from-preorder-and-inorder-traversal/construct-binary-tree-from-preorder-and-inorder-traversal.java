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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
     //pre root left right
     //inorder left root right
     Map<Integer,Integer> mp = new HashMap<>();
     for(int i=0;i<inorder.length;i++)
     {
        mp.put(inorder[i],i);
     }
        return Helper(0,preorder.length-1,preorder,0,inorder.length-1,inorder,mp);
    }
    public TreeNode Helper(int ps, int pe, int[] pre, int is, int ie,int[] in,Map<Integer,Integer> mp){
       if(ps>pe || is>ie) return null;
       TreeNode root = new TreeNode(pre[ps]);
       int rootIndex = mp.get(root.val);
       int leftSize = rootIndex-is;
       root.left = Helper(ps+1,ps+leftSize,pre,is,rootIndex-1,in,mp);
       root.right = Helper(ps+leftSize+1,pe,pre,rootIndex+1,ie,in,mp);
       return root;
       
    }
}