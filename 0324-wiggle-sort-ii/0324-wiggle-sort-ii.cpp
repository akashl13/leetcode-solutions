
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int mid = (n - 1) / 2;
        int high = n - 1;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = temp[mid--];
            } else {
                nums[i] = temp[high--];
            }
        }
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna