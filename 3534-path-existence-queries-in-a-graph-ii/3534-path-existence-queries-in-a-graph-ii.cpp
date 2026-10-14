class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {
        vector<pair<int, int>> nodes;

        for (int i = 0; i < n; i++) {
            nodes.push_back({nums[i], i});
        }

        sort(nodes.begin(), nodes.end());

        vector<int> pos(n), component(n);
        int comp = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0 &&
                nodes[i].first - nodes[i - 1].first > maxDiff) {
                comp++;
            }

            pos[nodes[i].second] = i;
            component[nodes[i].second] = comp;
        }

        // nxt[i] = farthest sorted position reachable from i in one step
        vector<int> nxt(n);
        int j = 0;

        for (int i = 0; i < n; i++) {
            j = max(j, i);

            while (j + 1 < n &&
                   nodes[j + 1].first - nodes[i].first <= maxDiff) {
                j++;
            }

            nxt[i] = j;
        }

        // Binary lifting for fast minimum-jump queries
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int u = q[0], v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (component[u] != component[v]) {
                ans.push_back(-1);
                continue;
            }

            int l = pos[u], r = pos[v];

            if (l > r) swap(l, r);

            int distance = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][l] < r && up[k][l] > l) {
                    l = up[k][l];
                    distance += (1 << k);
                }
            }

            ans.push_back(distance + 1);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna