class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(
        string s,
        vector<vector<int>>& queries
    ) {
        int n = s.size();

        // Total number of active sections in the whole string.
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1')
                totalOnes++;
        }

        // Store all zero blocks.
        vector<int> starts, ends, len;

        for (int i = 0; i < n; ) {
            if (s[i] == '1') {
                i++;
                continue;
            }

            int l = i;

            while (i < n && s[i] == '0')
                i++;

            int r = i - 1;

            starts.push_back(l);
            ends.push_back(r);
            len.push_back(r - l + 1);
        }

        int m = starts.size();

        // pair[i] = length of zero block i + zero block i+1
        vector<int> pairValue(max(0, m - 1));

        for (int i = 0; i + 1 < m; i++) {
            pairValue[i] = len[i] + len[i + 1];
        }

        // Segment tree for maximum pairValue.
        vector<int> seg(4 * max(1, m));

        function<void(int,int,int)> build =
            [&](int node, int l, int r) {
                if (l == r) {
                    if (l < (int)pairValue.size())
                        seg[node] = pairValue[l];
                    return;
                }

                int mid = (l + r) / 2;

                build(node * 2, l, mid);
                build(node * 2 + 1, mid + 1, r);

                seg[node] = max(seg[node * 2],
                                seg[node * 2 + 1]);
            };

        function<int(int,int,int,int,int)> rangeMax =
            [&](int node, int l, int r, int ql, int qr) -> int {

                if (ql > r || qr < l)
                    return 0;

                if (ql <= l && r <= qr)
                    return seg[node];

                int mid = (l + r) / 2;

                return max(
                    rangeMax(node * 2, l, mid, ql, qr),
                    rangeMax(node * 2 + 1, mid + 1, r, ql, qr)
                );
            };

        if (m > 1)
            build(1, 0, m - 2);

        // First zero block that intersects [L, R].
        auto firstBlock = [&](int L) {
            int lo = 0, hi = m - 1;
            int ans = m;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (ends[mid] >= L) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            return ans;
        };

        // Last zero block that intersects [L, R].
        auto lastBlock = [&](int R) {
            int lo = 0, hi = m - 1;
            int ans = -1;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (starts[mid] <= R) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            return ans;
        };

        vector<int> answer;

        for (auto &q : queries) {
            int L = q[0];
            int R = q[1];

            // Start with the original number of active sections.
            int best = totalOnes;

            if (m < 2) {
                answer.push_back(best);
                continue;
            }

            int a = firstBlock(L);
            int b = lastBlock(R);

            // Fewer than two zero blocks -> no valid trade.
            if (a >= m || b < 0 || a >= b) {
                answer.push_back(best);
                continue;
            }

            // Length of the first zero block inside [L, R].
            int firstLen =
                min(ends[a], R) - max(starts[a], L) + 1;

            // Length of the last zero block inside [L, R].
            int lastLen =
                min(ends[b], R) - max(starts[b], L) + 1;

            // Exactly two zero blocks.
            if (a + 1 == b) {
                int gain = firstLen + lastLen;
                best = max(best, totalOnes + gain);
            }
            else {
                // Pair involving the first zero block.
                int gainFirst = firstLen + len[a + 1];

                best = max(
                    best,
                    totalOnes + gainFirst
                );

                // Pair involving the last zero block.
                int gainLast = len[b - 1] + lastLen;

                best = max(
                    best,
                    totalOnes + gainLast
                );

                // Completely internal pairs.
                //
                // pairValue[i] represents zero block i
                // + zero block i+1.
                //
                // Internal pairs are i = a+1 ... b-2.
                if (a + 1 <= b - 2) {
                    int internalBest =
                        rangeMax(
                            1,
                            0,
                            m - 2,
                            a + 1,
                            b - 2
                        );

                    best = max(
                        best,
                        totalOnes + internalBest
                    );
                }
            }

            answer.push_back(best);
        }

        return answer;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna