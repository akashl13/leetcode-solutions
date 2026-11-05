
class Solution {

    public TreeNode sortedArrayToBST(int[] nums) {
        return buildTree(nums, 0, nums.length - 1);
    }

    private TreeNode buildTree(int[] nums, int left, int right) {

        // Base case
        if (left > right) {
            return null;
        }

        // Find middle element
        int mid = left + (right - left) / 2;

        // Create root node
        TreeNode root = new TreeNode(nums[mid]);

        // Build left subtree
        root.left = buildTree(nums, left, mid - 1);

        // Build right subtree
        root.right = buildTree(nums, mid + 1, right);

        return root;
    }
}
