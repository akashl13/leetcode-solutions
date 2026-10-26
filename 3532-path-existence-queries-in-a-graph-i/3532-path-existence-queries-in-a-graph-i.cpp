class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums,
                                      int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> component(n, 0);
        int id = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                id++;
            }
            component[i] = id;
        }

        vector<bool> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            answer.push_back(component[q[0]] == component[q[1]]);
        }

        return answer;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna