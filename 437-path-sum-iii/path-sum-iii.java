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
    int ans=0;
    public int pathSum(TreeNode root, int targetSum) {
        if(root==null) return 0;
        Map<Long,Integer> count = new HashMap<>();
        Helper(root,0,targetSum,count);
        return ans;
    }
    void Helper(TreeNode root,long sum, int targetSum,Map<Long,Integer> count)
    {
        if(root == null) return;
        sum+=root.val;
        if(sum==targetSum) ans++;
       
        ans +=count.getOrDefault(sum-targetSum,0);
        
        count.put(sum,count.getOrDefault(sum,0)+1);
        Helper(root.left,sum,targetSum,count);
        Helper(root.right,sum,targetSum,count);
        count.put(sum,count.get(sum)-1);
        sum -=root.val;
    }
}