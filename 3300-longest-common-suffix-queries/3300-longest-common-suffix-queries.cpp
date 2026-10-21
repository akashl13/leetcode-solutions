
class Solution {
public:
    struct Node {
        int children[26];
        int bestIndex;

        Node() {
            fill(children, children + 26, -1);
            bestIndex = -1;
        }
    };

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        vector<Node> trie(1);

        int bestOverall = 0;

        // Choose the shortest word; ties go to the earliest index.
        for (int i = 1; i < wordsContainer.size(); i++) {
            if (wordsContainer[i].size() <
                wordsContainer[bestOverall].size()) {
                bestOverall = i;
            }
        }

        trie[0].bestIndex = bestOverall;

        // Insert words in reverse order.
        for (int i = 0; i < wordsContainer.size(); i++) {
            int node = 0;

            for (int j = (int)wordsContainer[i].size() - 1;
                 j >= 0; j--) {
                int c = wordsContainer[i][j] - 'a';

                if (trie[node].children[c] == -1) {
                    trie[node].children[c] = trie.size();
                    trie.emplace_back();
                }

                node = trie[node].children[c];

                int old = trie[node].bestIndex;

                if (old == -1 ||
                    wordsContainer[i].size() <
                        wordsContainer[old].size()) {
                    trie[node].bestIndex = i;
                }
            }
        }

        vector<int> ans;

        for (const string& q : wordsQuery) {
            int node = 0;
            int best = trie[0].bestIndex;

            for (int j = (int)q.size() - 1; j >= 0; j--) {
                int c = q[j] - 'a';

                if (trie[node].children[c] == -1)
                    break;

                node = trie[node].children[c];
                best = trie[node].bestIndex;
            }

            ans.push_back(best);
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna