
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Case 1: nums is a cyclic increasing permutation
        int c = nums[0];
        bool increasing = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (i + c) % n) {
                increasing = false;
                break;
            }
        }

        if (increasing) {
            int k = (n - c) % n;

            if (k == 0) return 0;

            return min(k, n - k + 2);
        }

        // Case 2: nums is a cyclic decreasing permutation
        c = nums[0];
        bool decreasing = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (c - i + n) % n) {
                decreasing = false;
                break;
            }
        }

        if (decreasing) {
            int k = (n - c - 1 + n) % n;
            return min(k, n - k) + 1;
        }

        // Neither pattern is possible
        return -1;
    }
};
