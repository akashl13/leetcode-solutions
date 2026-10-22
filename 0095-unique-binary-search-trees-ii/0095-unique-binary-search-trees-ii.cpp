
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

private:
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> trees;

        // Empty range: one possible subtree, which is null
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        // Try every value as the root
        for (int rootVal = start; rootVal <= end; rootVal++) {
            vector<TreeNode*> leftTrees = build(start, rootVal - 1);
            vector<TreeNode*> rightTrees = build(rootVal + 1, end);

            // Combine every left subtree with every right subtree
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }
};
