class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> firstUpper(26, -1);
        vector<int> lastLower(26, -1);

        for (int i = 0; i < word.size(); i++) {

            char c = word[i];

            if (c >= 'a' && c <= 'z') {
                lastLower[c - 'a'] = i;
            }
            else {
                // Store only the first uppercase occurrence
                if (firstUpper[c - 'A'] == -1) {
                    firstUpper[c - 'A'] = i;
                }
            }
        }

        int answer = 0;

        for (int i = 0; i < 26; i++) {

            // Letter exists in both cases AND
            // every lowercase occurrence is before
            // the first uppercase occurrence
            if (lastLower[i] != -1 &&
                firstUpper[i] != -1 &&
                lastLower[i] < firstUpper[i]) {

                answer++;
            }
        }

        return answer;
    }
};