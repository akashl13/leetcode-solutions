#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n, LOG;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth;
    vector<int> bit;
    string s;
    int timer = 0;

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[0][u] = p;

        for (int k = 1; k < LOG; ++k) {
            up[k][u] = up[k - 1][up[k - 1][u]];
        }

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    void bitUpdate(int idx, int mask) {
        for (int i = idx; i <= n; i += i & -i) {
            bit[i] ^= mask;
        }
    }

    int bitQuery(int idx) {
        int result = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            result ^= bit[i];
        }
        return result;
    }

    int prefixMask(int u) {
        return bitQuery(tin[u]);
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int k = 0; k < LOG; ++k) {
            if (diff & (1 << k)) {
                u = up[k][u];
            }
        }

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; --k) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        this->n = n;
        this->s = s;
        timer = 0;

        LOG = 1;
        while ((1 << LOG) <= n) ++LOG;

        adj.assign(n, {});
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        up.assign(LOG, vector<int>(n, 0));
        bit.assign(n + 1, 0);

        dfs(0, 0);

        // Each node contributes its character mask to its subtree.
        for (int u = 0; u < n; ++u) {
            int mask = 1 << (s[u] - 'a');
            bitUpdate(tin[u], mask);
            bitUpdate(tout[u] + 1, mask);
        }

        vector<bool> answer;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int change = oldMask ^ newMask;

                if (change != 0) {
                    bitUpdate(tin[u], change);
                    bitUpdate(tout[u] + 1, change);
                    s[u] = c;
                }
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                // XOR masks along the path, counting the LCA once.
                int mask = prefixMask(u) ^ prefixMask(v)
                         ^ (1 << (s[w] - 'a'));

                // A multiset can form a palindrome iff at most
                // one character has an odd frequency.
                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna