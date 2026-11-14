class Solution {
public:
    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        vector<vector<string>> ans;

        // endWord must exist
        if (!dict.count(endWord))
            return ans;

        // parent[word] = words that can reach word
        // on a shortest path
        unordered_map<string, vector<string>> parent;

        unordered_set<string> current;
        current.insert(beginWord);

        bool found = false;

        while (!current.empty() && !found) {

            // Remove current level words from dictionary
            // so we don't visit them again in later levels.
            for (const string& word : current)
                dict.erase(word);

            unordered_set<string> next;

            for (const string& word : current) {
                string temp = word;

                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original)
                            continue;

                        temp[i] = c;

                        if (dict.count(temp)) {
                            next.insert(temp);

                            // word -> temp
                            // means word is a parent of temp
                            parent[temp].push_back(word);

                            if (temp == endWord)
                                found = true;
                        }
                    }

                    temp[i] = original;
                }
            }

            current = next;
        }

        if (!found)
            return ans;

        // Build paths backwards from endWord
        vector<string> path;
        path.push_back(endWord);

        backtrack(endWord, beginWord, parent, path, ans);

        return ans;
    }

private:
    void backtrack(
        string word,
        string beginWord,
        unordered_map<string, vector<string>>& parent,
        vector<string>& path,
        vector<vector<string>>& ans
    ) {
        if (word == beginWord) {
            vector<string> result = path;

            reverse(result.begin(), result.end());

            ans.push_back(result);
            return;
        }

        for (const string& p : parent[word]) {
            path.push_back(p);

            backtrack(p, beginWord, parent, path, ans);

            path.pop_back();
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna