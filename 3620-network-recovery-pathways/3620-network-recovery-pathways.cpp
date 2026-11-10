class Solution {
public:
    long long K;

    bool can(int minCost,
             int n,
             vector<vector<pair<int, int>>>& graph,
             vector<bool>& online,
             vector<int>& topo) {

        const long long INF = 4e18;

        vector<long long> dp(n, INF);
        dp[0] = 0;

        for (int u : topo) {

            if (dp[u] == INF)
                continue;

            // Intermediate node must be online
            if (u != 0 && u != n - 1 && !online[u])
                continue;

            for (auto [v, cost] : graph[u]) {

                // Every edge must have cost >= minCost
                if (cost < minCost)
                    continue;

                // Intermediate destination must be online
                if (v != n - 1 && !online[v])
                    continue;

                long long newCost = dp[u] + cost;

                if (newCost <= K && newCost < dp[v]) {
                    dp[v] = newCost;
                }
            }
        }

        return dp[n - 1] <= K;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int, int>>> graph(n);
        vector<int> indegree(n, 0);

        int maxCost = 0;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int cost = e[2];

            graph[u].push_back({v, cost});
            indegree[v]++;

            maxCost = max(maxCost, cost);
        }

        // Topological sort using Kahn's algorithm
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (auto [v, cost] : graph[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        K = k;

        // Binary search the answer
        int low = 0;
        int high = maxCost;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (can(mid, n, graph, online, topo)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna