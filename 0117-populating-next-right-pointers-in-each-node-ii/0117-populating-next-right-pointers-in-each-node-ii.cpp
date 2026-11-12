/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* curr = root;

        while (curr != nullptr) {
            Node dummy(0);
            Node* tail = &dummy;

            // Traverse current level using next pointers
            while (curr != nullptr) {
                if (curr->left != nullptr) {
                    tail->next = curr->left;
                    tail = tail->next;
                }

                if (curr->right != nullptr) {
                    tail->next = curr->right;
                    tail = tail->next;
                }

                curr = curr->next;
            }

            // Move to first node of next level
            curr = dummy.next;
        }

        return root;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna