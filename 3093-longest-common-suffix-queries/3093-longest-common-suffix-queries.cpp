class Solution {
public:

    struct TrieNode {
        int child[26];
        int bestIndex;

        TrieNode() {
            fill(child, child + 26, -1);
            bestIndex = -1;
        }
    };

    vector<TrieNode> trie;

    // Check which word is better for tie-breaking
    bool better(int a, int b, vector<string>& words) {

        if (b == -1)
            return true;

        // Shorter word wins
        if (words[a].size() != words[b].size())
            return words[a].size() < words[b].size();

        // If same length, earlier index wins
        return a < b;
    }

    void insert(string& word, int index, vector<string>& words) {

        int node = 0;

        // Insert from the end
        for (int i = word.size() - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(TrieNode());
            }

            node = trie[node].child[c];

            // Best word for this suffix
            if (better(index, trie[node].bestIndex, words)) {
                trie[node].bestIndex = index;
            }
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.push_back(TrieNode());

        // Insert all container words
        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        // Root represents empty suffix
        int defaultIndex = 0;

        for (int i = 1; i < wordsContainer.size(); i++) {
            if (better(i, defaultIndex, wordsContainer)) {
                defaultIndex = i;
            }
        }

        vector<int> answer;

        for (string& word : wordsQuery) {

            int node = 0;
            int best = defaultIndex;

            // Traverse query from right to left
            for (int i = word.size() - 1; i >= 0; i--) {

                int c = word[i] - 'a';

                // No longer suffix exists
                if (trie[node].child[c] == -1)
                    break;

                node = trie[node].child[c];

                // This node represents a longer common suffix
                best = trie[node].bestIndex;
            }

            answer.push_back(best);
        }

        return answer;
    }
};