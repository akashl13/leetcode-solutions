
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);

        return dfs(arr, start, visited);
    }

    bool dfs(vector<int>& arr, int i, vector<bool>& visited) {
        // Out of bounds or already visited
        if (i < 0 || i >= arr.size() || visited[i]) {
            return false;
        }

        // Found a zero
        if (arr[i] == 0) {
            return true;
        }

        // Mark this index as visited
        visited[i] = true;

        // Try both jump directions
        return dfs(arr, i + arr[i], visited) ||
               dfs(arr, i - arr[i], visited);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna