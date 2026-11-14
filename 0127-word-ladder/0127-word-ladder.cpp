class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> words(wordList.begin(), wordList.end());

        // endWord must be present
        if (!words.count(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            // Process one level at a time
            while (size--) {
                string word = q.front();
                q.pop();

                // Try changing every character
                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original)
                            continue;

                        word[i] = c;

                        // Found the end word
                        if (word == endWord)
                            return level + 1;

                        // Valid unused word
                        if (words.count(word)) {
                            q.push(word);

                            // Mark as visited
                            words.erase(word);
                        }
                    }

                    word[i] = original;
                }
            }

            level++;
        }

        return 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna