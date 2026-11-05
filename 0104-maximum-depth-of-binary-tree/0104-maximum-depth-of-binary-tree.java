
class Solution {
    public int maxDepth(TreeNode root) {

        // Base case: empty tree
        if (root == null) {
            return 0;
        }

        // Find left subtree depth
        int left = maxDepth(root.left);

        // Find right subtree depth
        int right = maxDepth(root.right);

        // Return maximum depth
        return 1 + Math.max(left, right);
    }
}
