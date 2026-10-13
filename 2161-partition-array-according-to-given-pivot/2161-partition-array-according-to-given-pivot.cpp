class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;

        for (int x : nums) {
            if (x < pivot) {
                result.push_back(x);
            }
        }

        for (int x : nums) {
            if (x == pivot) {
                result.push_back(x);
            }
        }

        for (int x : nums) {
            if (x > pivot) {
                result.push_back(x);
            }
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna