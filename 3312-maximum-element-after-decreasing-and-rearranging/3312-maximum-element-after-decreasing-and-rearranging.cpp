class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1] + 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }

        return arr.back();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna