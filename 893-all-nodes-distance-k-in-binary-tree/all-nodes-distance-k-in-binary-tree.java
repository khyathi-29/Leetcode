/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Set<TreeNode> vis = new HashSet<>();
        Map<TreeNode,TreeNode> mp = new HashMap<>();
        getParent(root,mp);
        List<Integer> ans = new ArrayList<>();
        Helper(target, k,mp,ans,vis);
        return ans;
     
    }
    void  Helper(TreeNode root, int target,Map<TreeNode,TreeNode> mp,List<Integer> ans,Set<TreeNode> vis){
        if(root==null) return ;
        if(target==0 && vis.contains(root)==false){
            ans.add(root.val);
            return;
        }
        if(vis.contains(root)==true) return;//already visited node
        vis.add(root);
        Helper(root.left,target-1,mp,ans,vis);
        Helper(root.right,target-1,mp,ans,vis);
         if(mp.containsKey(root)==true && vis.contains(mp.get(root))==false)
         {
            Helper(mp.get(root),target-1,mp,ans,vis);
         }
    }
    void getParent(TreeNode root, Map<TreeNode,TreeNode> mp)
    {
        if(root==null) return;
        if(root.left!=null){
            mp.put(root.left,root);
            getParent(root.left,mp);
        }
        if(root.right!=null){
            mp.put(root.right,root);
            getParent(root.right,mp);
        }
    }
}