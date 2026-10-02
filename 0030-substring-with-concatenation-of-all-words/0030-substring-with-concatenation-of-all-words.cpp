class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (totalLen > s.length())
            return ans;

        // Count how many times each word should appear
        unordered_map<string, int> need;

        for (string word : words) {
            need[word]++;
        }

        // Try each possible starting offset
        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int count = 0;

            unordered_map<string, int> have;

            for (int right = offset;
                 right + wordLen <= s.length();
                 right += wordLen) {

                string word = s.substr(right, wordLen);

                // Word is not in words
                if (need.find(word) == need.end()) {
                    have.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                have[word]++;
                count++;

                // Too many copies of this word
                while (have[word] > need[word]) {

                    string leftWord = s.substr(left, wordLen);

                    have[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // We have exactly all words
                if (count == wordCount) {
                    ans.push_back(left);

                    // Move forward to search for another answer
                    string leftWord = s.substr(left, wordLen);
                    have[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};