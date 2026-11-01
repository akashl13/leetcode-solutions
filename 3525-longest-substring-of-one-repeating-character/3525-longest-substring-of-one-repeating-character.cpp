
class Solution {
    struct Node {
        int len;
        char leftChar, rightChar;
        int prefix, suffix, best;
    };

    vector<Node> tree;
    string s;
    int n;

    Node merge(Node a, Node b) {
        Node res;
        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;
        res.prefix = a.prefix;
        res.suffix = b.suffix;
        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suffix + b.prefix);

            if (a.prefix == a.len)
                res.prefix = a.len + b.prefix;

            if (b.suffix == b.len)
                res.suffix = b.len + a.suffix;
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = {1, s[l], s[l], 1, 1, 1};
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            s[idx] = c;
            tree[node] = {1, c, c, 1, 1, 1};
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {
        this->s = s;
        n = s.size();
        tree.resize(4 * n);

        build(1, 0, n - 1);

        int k = queryCharacters.size();
        vector<int> ans;
        ans.reserve(k);

        for (int i = 0; i < k; i++) {
            update(1, 0, n - 1,
                   queryIndices[i], queryCharacters[i]);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna