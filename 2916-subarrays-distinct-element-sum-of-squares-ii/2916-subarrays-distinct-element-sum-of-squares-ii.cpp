class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum1 = 0, sum2 = 0, lazy = 0;
    };

    vector<Node> seg;
    int n;

    void apply(int p, int l, int r, long long v) {
        long long len = r - l + 1;
        seg[p].sum2 = (seg[p].sum2 + 2 * v % MOD * seg[p].sum1 % MOD
                       + v * v % MOD * len) % MOD;
        seg[p].sum1 = (seg[p].sum1 + v * len) % MOD;
        seg[p].lazy = (seg[p].lazy + v) % MOD;
    }

    void push(int p, int l, int r) {
        if (seg[p].lazy == 0 || l == r) return;

        int mid = (l + r) / 2;
        apply(p * 2, l, mid, seg[p].lazy);
        apply(p * 2 + 1, mid + 1, r, seg[p].lazy);
        seg[p].lazy = 0;
    }

    void update(int p, int l, int r, int ql, int qr, long long v) {
        if (ql <= l && r <= qr) {
            apply(p, l, r, v);
            return;
        }

        push(p, l, r);
        int mid = (l + r) / 2;

        if (ql <= mid) update(p * 2, l, mid, ql, qr, v);
        if (qr > mid) update(p * 2 + 1, mid + 1, r, ql, qr, v);

        seg[p].sum1 = (seg[p * 2].sum1 + seg[p * 2 + 1].sum1) % MOD;
        seg[p].sum2 = (seg[p * 2].sum2 + seg[p * 2 + 1].sum2) % MOD;
    }

    long long query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return seg[p].sum2;

        push(p, l, r);
        int mid = (l + r) / 2;
        long long ans = 0;

        if (ql <= mid) ans += query(p * 2, l, mid, ql, qr);
        if (qr > mid) ans += query(p * 2 + 1, mid + 1, r, ql, qr);

        return ans % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n + 5, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int left = last[nums[i]] + 1;

            // Increase distinct counts for subarrays ending at i.
            update(1, 0, n - 1, left, i, 1);

            // Add squares of distinct counts for all subarrays ending at i.
            ans = (ans + query(1, 0, n - 1, 0, i)) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna