
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;

        for (char c : s) {
            if (c == '1') {
                ones++;
            }
        }

        string t = "1" + s + "1";
        int bestGain = 0;
        int m = t.size();

        // Find a 0-block, then a 1-block, then another 0-block
        for (int i = 0; i < m; ) {
            int j = i;

            while (j < m && t[j] == t[i]) {
                j++;
            }

            if (t[i] == '0') {
                int leftZero = j - i;

                if (j < m && t[j] == '1') {
                    int k = j;

                    while (k < m && t[k] == '1') {
                        k++;
                    }

                    if (k < m && t[k] == '0') {
                        int rightZero = 0;

                        while (k < m && t[k] == '0') {
                            rightZero++;
                            k++;
                        }

                        bestGain = max(bestGain, leftZero + rightZero);
                    }
                }
            }

            i = j;
        }

        return ones + bestGain;
    }
};
