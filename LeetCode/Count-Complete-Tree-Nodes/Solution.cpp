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
    int findHeightRight(TreeNode root){
        TreeNode temp=root;
        int h=0;//storing the height
        while(temp!=null){
            h++;
            temp=temp.right;
        }
        return h;
    }


        int findHeightLeft(TreeNode root){
        TreeNode temp=root;
        int h=0;//storing the height
        while(temp!=null){
            h++;
            temp=temp.left;
        }
        return h;
    }


    public int countNodes(TreeNode root) {
        if(root==null)return 0;
        int lh=findHeightLeft(root);
        int rh=findHeightRight(root);

        if(lh==rh)return (1<<lh)-1;

        return 1+countNodes(root.left)+countNodes(root.right);
    }
}