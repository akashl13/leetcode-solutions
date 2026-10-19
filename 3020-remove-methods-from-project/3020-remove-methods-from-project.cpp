class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for (auto& e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        // Find all suspicious methods reachable from k.
        vector<bool> suspicious(n, false);
        queue<int> q;

        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        // If a non-suspicious method invokes a suspicious method,
        // we cannot remove the suspicious group.
        for (auto& e : invocations) {
            int a = e[0];
            int b = e[1];

            if (!suspicious[a] && suspicious[b]) {
                vector<int> ans;
                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }
                return ans;
            }
        }

        // Safe to remove all suspicious methods.
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna