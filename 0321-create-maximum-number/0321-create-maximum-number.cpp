
class Solution {
public:

    // Get maximum subsequence of length k
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int drop = nums.size() - k;

        for (int x : nums) {
            while (!st.empty() && drop > 0 && st.back() < x) {
                st.pop_back();
                drop--;
            }

            st.push_back(x);
        }

        st.resize(k);
        return st;
    }

    // Compare remaining elements lexicographically
    bool greater(vector<int>& a, int i,
                 vector<int>& b, int j) {
        while (i < a.size() && j < b.size() &&
               a[i] == b[j]) {
            i++;
            j++;
        }

        if (j == b.size()) return true;
        if (i == a.size()) return false;

        return a[i] > b[j];
    }

    // Merge two subsequences
    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {
            if (greater(a, i, b, j)) {
                res.push_back(a[i++]);
            } else {
                res.push_back(b[j++]);
            }
        }

        return res;
    }

    vector<int> maxNumber(vector<int>& nums1,
                          vector<int>& nums2, int k) {

        int m = nums1.size();
        int n = nums2.size();

        vector<int> ans(k, 0);

        for (int i = max(0, k - n); i <= min(k, m); i++) {

            int j = k - i;

            vector<int> a = maxSubsequence(nums1, i);
            vector<int> b = maxSubsequence(nums2, j);

            vector<int> candidate = merge(a, b);

            if (greater(candidate, 0, ans, 0)) {
                ans = candidate;
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna