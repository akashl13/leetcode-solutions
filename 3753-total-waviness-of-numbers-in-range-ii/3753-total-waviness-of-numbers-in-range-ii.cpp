class Solution {
public:
    using ll = long long;

    struct Node {
        ll count, waviness;
    };

    string s;
    Node memo[17][11][11][2][2];
    bool vis[17][11][11][2][2];

    Node dfs(int pos, int prev2, int prev1, int started, int tight) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        Node &res = memo[pos][prev2][prev1][started][tight];

        if (vis[pos][prev2][prev1][started][tight]) {
            return res;
        }

        vis[pos][prev2][prev1][started][tight] = true;
        res = {0, 0};

        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            int ntight = tight && (d == s[pos] - '0');

            Node child;
            int nprev2 = prev2, nprev1 = prev1;
            int nstarted = started;
            int add = 0;

            if (!started && d == 0) {
                child = dfs(pos + 1, 10, 10, 0, ntight);
            } else if (!started) {
                child = dfs(pos + 1, 10, d, 1, ntight);
            } else {
                if (prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d)) {
                        add = 1;
                    }
                }

                child = dfs(pos + 1, prev1, d, 1, ntight);
            }

            res.count += child.count;
            res.waviness += child.waviness + 1LL * add * child.count;
        }

        return res;
    }

    ll calc(ll x) {
        if (x <= 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, 0, 1).waviness;
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna