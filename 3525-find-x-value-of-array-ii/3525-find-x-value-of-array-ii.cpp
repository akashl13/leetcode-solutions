
class Solution {
    struct Node {
        int len = 0;
        int prod = 1;
        vector<int> pref;

        Node(int k = 1) : pref(k, 0) {}
    };

    int n, k;
    vector<Node> seg;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res(k);
        res.len = a.len + b.len;
        res.prod = (a.prod * b.prod) % k;

        // Prefixes ending inside the left segment.
        for (int r = 0; r < k; r++) {
            res.pref[r] += a.pref[r];
        }

        // Prefixes that include all of the left segment
        // and a non-empty prefix of the right segment.
        for (int r = 0; r < k; r++) {
            int rem = (a.prod * r) % k;
            res.pref[rem] += b.pref[r];
        }

        return res;
    }

    Node makeNode(int value) {
        Node res(k);
        res.len = 1;
        res.prod = value % k;
        res.pref[res.prod] = 1;
        return res;
    }

    void build(int node, int l, int r,
               vector<int>& nums) {
        if (l == r) {
            seg[node] = makeNode(nums[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        seg[node] = merge(seg[node * 2],
                          seg[node * 2 + 1]);
    }

    void update(int node, int l, int r,
                int idx, int value) {
        if (l == r) {
            seg[node] = makeNode(value);
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, value);
        } else {
            update(node * 2 + 1, mid + 1, r,
                   idx, value);
        }

        seg[node] = merge(seg[node * 2],
                          seg[node * 2 + 1]);
    }

    Node query(int node, int l, int r,
               int ql, int qr) {
        if (qr < l || r < ql) {
            return Node(k);
        }

        if (ql <= l && r <= qr) {
            return seg[node];
        }

        int mid = l + (r - l) / 2;

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r,
                           ql, qr);

        return merge(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        n = nums.size();
        this->k = k;

        seg.assign(4 * n, Node(k));

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persist the update.
            nums[index] = value;
            update(1, 0, n - 1, index, value);

            // Count non-empty prefixes of nums[start..n-1].
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.pref[x]);
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna