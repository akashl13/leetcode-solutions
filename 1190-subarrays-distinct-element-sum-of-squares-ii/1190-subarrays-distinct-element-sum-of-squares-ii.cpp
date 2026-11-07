class Solution {
public:
    static const long long MOD = 1000000007LL;

    struct Node {
        long long sum = 0;   // sum of distinct counts
        long long sq = 0;    // sum of squares
        long long lazy = 0;  // pending +1
    };

    vector<Node> seg;

    void apply(int p, int l, int r, long long v) {
        long long len = r - l + 1;

        // (x + v)^2 = x^2 + 2vx + v^2
        seg[p].sq = (
            seg[p].sq
            + 2LL * v % MOD * seg[p].sum
            + v * v % MOD * len
        ) % MOD;

        seg[p].sum = (
            seg[p].sum + v * len
        ) % MOD;

        seg[p].lazy = (seg[p].lazy + v) % MOD;
    }

    void push(int p, int l, int r) {
        if (seg[p].lazy == 0 || l == r)
            return;

        int mid = (l + r) / 2;
        long long v = seg[p].lazy;

        apply(p * 2, l, mid, v);
        apply(p * 2 + 1, mid + 1, r, v);

        seg[p].lazy = 0;
    }

    void update(int p, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply(p, l, r, 1);
            return;
        }

        push(p, l, r);

        int mid = (l + r) / 2;

        update(p * 2, l, mid, ql, qr);
        update(p * 2 + 1, mid + 1, r, ql, qr);

        seg[p].sum = (
            seg[p * 2].sum +
            seg[p * 2 + 1].sum
        ) % MOD;

        seg[p].sq = (
            seg[p * 2].sq +
            seg[p * 2 + 1].sq
        ) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        seg.assign(4 * n + 5, Node());

        vector<int> last(100001, -1);

        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int x = nums[r];

            int prev = last[x];

            // For left endpoints:
            // [prev + 1 ... r] gets +1 distinct value.
            update(1, 0, n - 1, prev + 1, r);

            last[x] = r;

            // Sum of squares of all subarrays ending at r.
            ans = (ans + seg[1].sq) % MOD;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna