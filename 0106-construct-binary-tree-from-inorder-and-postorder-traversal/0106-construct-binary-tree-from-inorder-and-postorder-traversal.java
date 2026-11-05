
import java.util.*;

class Solution {

    private int postIndex;
    private HashMap<Integer, Integer> inorderMap;

    public TreeNode buildTree(int[] inorder, int[] postorder) {

        postIndex = postorder.length - 1;
        inorderMap = new HashMap<>();

        // Store inorder values and their indices
        for (int i = 0; i < inorder.length; i++) {
            inorderMap.put(inorder[i], i);
        }

        return construct(postorder, 0, inorder.length - 1);
    }

    private TreeNode construct(int[] postorder, int left, int right) {

        // Base case
        if (left > right) {
            return null;
        }

        // Last element in postorder is the root
        int rootValue = postorder[postIndex--];

        TreeNode root = new TreeNode(rootValue);

        // Find root position in inorder
        int mid = inorderMap.get(rootValue);

        // Build right subtree first
        root.right = construct(postorder, mid + 1, right);

        // Build left subtree
        root.left = construct(postorder, left, mid - 1);

        return root;
    }
}
