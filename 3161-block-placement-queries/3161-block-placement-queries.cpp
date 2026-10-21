
class Solution {
    static const int MAXX = 150005;

    int seg[4 * MAXX];
    int gap[MAXX];

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        return max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int maxX = 0;

        for (auto& q : queries)
            maxX = max(maxX, q[1]);

        maxX += 2;

        memset(seg, 0, sizeof(seg));

        set<int> obstacles = {0, maxX};

        // Initially, the gap from coordinate 0 to maxX is maxX.
        update(1, 0, maxX, 0, maxX);

        vector<bool> ans;

        for (auto& q : queries) {
            int type = q[0];
            int x = q[1];

            if (type == 1) {
                auto it = obstacles.lower_bound(x);
                int right = *it;
                int left = *prev(it);

                obstacles.insert(x);

                // The old gap is replaced by two smaller gaps.
                update(1, 0, maxX, left, x - left);
                update(1, 0, maxX, x, right - x);
            } else {
                int sz = q[2];

                // Find the greatest obstacle <= x.
                auto it = obstacles.upper_bound(x);
                --it;
                int last = *it;

                // Largest complete gap before the last obstacle.
                int best = query(1, 0, maxX, 0, last - 1);

                // Also consider the remaining interval [last, x].
                best = max(best, x - last);

                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna