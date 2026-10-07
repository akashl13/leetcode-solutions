class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int MAXX = 0;

        for (auto &q : queries) {
            MAXX = max(MAXX, q[1]);
        }

        vector<int> seg(4 * (MAXX + 2), 0);

        // Segment Tree Update
        auto update = [&](auto&& self, int node, int l, int r,
                          int pos, int val) -> void {

            if (l == r) {
                seg[node] = val;
                return;
            }

            int mid = (l + r) / 2;

            if (pos <= mid) {
                self(self, node * 2, l, mid, pos, val);
            }
            else {
                self(self, node * 2 + 1, mid + 1, r, pos, val);
            }

            seg[node] = max(seg[node * 2],
                            seg[node * 2 + 1]);
        };

        // Segment Tree Query
        auto query = [&](auto&& self, int node, int l, int r,
                         int ql, int qr) -> int {

            if (qr < l || r < ql) {
                return 0;
            }

            if (ql <= l && r <= qr) {
                return seg[node];
            }

            int mid = (l + r) / 2;

            return max(
                self(self, node * 2, l, mid, ql, qr),
                self(self, node * 2 + 1, mid + 1, r, ql, qr)
            );
        };

        set<int> obstacles;

        // Origin
        obstacles.insert(0);

        vector<bool> ans;

        for (auto &q : queries) {

            int type = q[0];
            int x = q[1];

            // -------------------------
            // Type 1: Add obstacle
            // -------------------------
            if (type == 1) {

                auto it = obstacles.lower_bound(x);

                int next = MAXX + 1;

                if (it != obstacles.end()) {
                    next = *it;
                }

                // IMPORTANT:
                // Use std::prev() before declaring 'previous'
                int previous = *std::prev(it);

                obstacles.insert(x);

                // Gap: previous -> x
                update(update, 1, 0, MAXX + 1,
                       x, x - previous);

                // Gap: x -> next
                if (next <= MAXX) {
                    update(update, 1, 0, MAXX + 1,
                           next, next - x);
                }
            }

            // -------------------------
            // Type 2: Check block
            // -------------------------
            else {

                int sz = q[2];

                // First obstacle strictly greater than x
                auto it = obstacles.upper_bound(x);

                int previous = *std::prev(it);

                // Gap from previous obstacle to x
                int finalGap = x - previous;

                bool possible = (finalGap >= sz);

                if (!possible) {

                    // Check complete gaps ending at
                    // obstacles <= x
                    int bestGap = query(
                        query,
                        1,
                        0,
                        MAXX + 1,
                        0,
                        x
                    );

                    possible = (bestGap >= sz);
                }

                ans.push_back(possible);
            }
        }

        return ans;
    }
};