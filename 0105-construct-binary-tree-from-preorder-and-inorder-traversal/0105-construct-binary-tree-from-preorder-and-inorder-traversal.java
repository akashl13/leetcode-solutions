
import java.util.*;

class Solution {

    private int preorderIndex;
    private HashMap<Integer, Integer> inorderMap;

    public TreeNode buildTree(int[] preorder, int[] inorder) {

        preorderIndex = 0;
        inorderMap = new HashMap<>();

        // Store inorder values and their indices
        for (int i = 0; i < inorder.length; i++) {
            inorderMap.put(inorder[i], i);
        }

        return construct(preorder, 0, inorder.length - 1);
    }

    private TreeNode construct(int[] preorder, int left, int right) {

        // Base case
        if (left > right) {
            return null;
        }

        // First element in preorder is the root
        int rootValue = preorder[preorderIndex++];

        TreeNode root = new TreeNode(rootValue);

        // Find root position in inorder
        int mid = inorderMap.get(rootValue);

        // Build left subtree
        root.left = construct(preorder, left, mid - 1);

        // Build right subtree
        root.right = construct(preorder, mid + 1, right);

        return root;
    }
}
