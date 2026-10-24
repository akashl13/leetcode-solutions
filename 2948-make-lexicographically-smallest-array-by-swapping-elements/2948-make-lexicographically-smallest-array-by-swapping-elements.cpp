
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> ans(n);
        int i = 0;

        while (i < n) {
            int j = i + 1;

            while (j < n && 
                   (long long)arr[j].first - arr[j - 1].first <= limit) {
                j++;
            }

            vector<int> indices;
            vector<int> values;

            for (int k = i; k < j; k++) {
                values.push_back(arr[k].first);
                indices.push_back(arr[k].second);
            }

            sort(indices.begin(), indices.end());

            for (int k = 0; k < (int)values.size(); k++) {
                ans[indices[k]] = values[k];
            }

            i = j;
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna