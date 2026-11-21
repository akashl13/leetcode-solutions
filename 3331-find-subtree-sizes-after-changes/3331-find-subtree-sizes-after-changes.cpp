class Solution {
public:
    vector<int> answer;
    vector<int> last;
    vector<vector<int>> tree, newTree;
    vector<int> newParent;

    void dfs1(int u, string &s) {
        int c = s[u] - 'a';

        int prev = last[c];

        if (prev != -1) {
            newParent[u] = prev;
        }

        last[c] = u;

        for (int v : tree[u]) {
            dfs1(v, s);
        }

        last[c] = prev;
    }

    int dfs2(int u) {
        int sz = 1;

        for (int v : newTree[u]) {
            sz += dfs2(v);
        }

        answer[u] = sz;
        return sz;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        tree.resize(n);
        newTree.resize(n);
        newParent = parent;

        answer.resize(n);
        last.assign(26, -1);

        // Build original tree
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        // Find new parents using original tree
        dfs1(0, s);

        // Build modified tree
        for (int i = 1; i < n; i++) {
            newTree[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        dfs2(0);

        return answer;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna