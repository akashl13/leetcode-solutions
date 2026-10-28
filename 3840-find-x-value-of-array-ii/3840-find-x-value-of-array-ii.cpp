class Solution {
    struct Node {
        int prod, len;
        vector<int> pref;

        Node(int k = 1) : prod(1 % k), len(0), pref(k, 0) {}
    };

    int n, k;
    vector<Node> tree;

    Node merge(const Node& a, const Node& b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res(k);
        res.len = a.len + b.len;
        res.prod = (a.prod * b.prod) % k;

        for (int r = 0; r < k; r++) {
            res.pref[r] += a.pref[r];

            int shifted = (a.prod * r) % k;
            res.pref[shifted] += b.pref[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            tree[node] = Node(k);
            tree[node].len = 1;
            tree[node].prod = nums[l] % k;
            tree[node].pref[tree[node].prod] = 1;
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = Node(k);
            tree[node].len = 1;
            tree[node].prod = val % k;
            tree[node].pref[tree[node].prod] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return Node(k);

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        this->n = nums.size();
        this->k = k;
        tree.assign(4 * n + 5, Node(k));

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            nums[idx] = value;
            update(1, 0, n - 1, idx, value);

            Node res = query(1, 0, n - 1, start, n - 1);
            ans.push_back(res.pref[x]);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna