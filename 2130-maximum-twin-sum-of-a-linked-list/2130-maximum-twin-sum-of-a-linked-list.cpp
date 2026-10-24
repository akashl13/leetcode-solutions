
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;

        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        int maxi = 0;

        for (int i = 0; i < n / 2; i++) {
            maxi = max(maxi, nums[i] + nums[n - 1 - i]);
        }

        return maxi;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna