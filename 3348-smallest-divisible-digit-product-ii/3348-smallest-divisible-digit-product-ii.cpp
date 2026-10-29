#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    using State = array<int, 4>;

    State req{};
    int A, B, C, D;
    vector<int> dp;

    const State factors[10] = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    };

    int id(int a, int b, int c, int d) const {
        return ((a * (B + 1) + b) * (C + 1) + c)
               * (D + 1) + d;
    }

    State reduceState(State s, int digit) const {
        for (int j = 0; j < 4; ++j) {
            s[j] = max(0, s[j] - factors[digit][j]);
        }
        return s;
    }

    int minDigits(const State& s) const {
        return dp[id(s[0], s[1], s[2], s[3])];
    }

    void buildDP() {
        A = req[0];
        B = req[1];
        C = req[2];
        D = req[3];

        dp.assign((A + 1) * (B + 1) * (C + 1) * (D + 1),
                  1000000000);

        dp[id(0, 0, 0, 0)] = 0;

        for (int a = 0; a <= A; ++a) {
            for (int b = 0; b <= B; ++b) {
                for (int c = 0; c <= C; ++c) {
                    for (int d = 0; d <= D; ++d) {
                        if (a == 0 && b == 0 && c == 0 && d == 0)
                            continue;

                        State s = {a, b, c, d};
                        int best = 1000000000;

                        for (int digit = 2; digit <= 9; ++digit) {
                            State next = reduceState(s, digit);

                            if (next == s)
                                continue;

                            best = min(
                                best,
                                1 + minDigits(next)
                            );
                        }

                        dp[id(a, b, c, d)] = best;
                    }
                }
            }
        }
    }

    string buildSmallest(State s, int length) const {
        string result;

        for (int pos = 0; pos < length; ++pos) {
            int remaining = length - pos - 1;

            for (int digit = 1; digit <= 9; ++digit) {
                State next = reduceState(s, digit);

                if (minDigits(next) <= remaining) {
                    result.push_back(char('0' + digit));
                    s = next;
                    break;
                }
            }
        }

        return result;
    }

public:
    string smallestNumber(string num, long long t) {
        // Factor t into powers of 2, 3, 5 and 7.
        long long x = t;
        req = {0, 0, 0, 0};

        while (x % 2 == 0) {
            ++req[0];
            x /= 2;
        }

        while (x % 3 == 0) {
            ++req[1];
            x /= 3;
        }

        while (x % 5 == 0) {
            ++req[2];
            x /= 5;
        }

        while (x % 7 == 0) {
            ++req[3];
            x /= 7;
        }

        // No digit from 1 to 9 can supply any other prime factor.
        if (x != 1)
            return "-1";

        buildDP();

        // Check whether num itself is a valid zero-free answer.
        State have = {0, 0, 0, 0};
        bool hasZero = false;

        for (char ch : num) {
            int digit = ch - '0';

            if (digit == 0) {
                hasZero = true;
                break;
            }

            for (int j = 0; j < 4; ++j) {
                have[j] = min(req[j], have[j] + factors[digit][j]);
            }
        }

        if (!hasZero && have == req)
            return num;

        int n = static_cast<int>(num.size());

        // Find the rightmost position that can be increased.
        for (int i = n - 1; i >= 0; --i) {
            State prefix = {0, 0, 0, 0};
            bool validPrefix = true;

            for (int j = 0; j < i; ++j) {
                int digit = num[j] - '0';

                if (digit == 0) {
                    validPrefix = false;
                    break;
                }

                for (int k = 0; k < 4; ++k) {
                    prefix[k] = min(
                        req[k],
                        prefix[k] + factors[digit][k]
                    );
                }
            }

            if (!validPrefix)
                continue;

            int current = num[i] - '0';

            for (int digit = max(1, current + 1); digit <= 9; ++digit) {
                State remaining = prefix;

                for (int k = 0; k < 4; ++k) {
                    remaining[k] = min(
                        req[k],
                        remaining[k] + factors[digit][k]
                    );
                }

                for (int k = 0; k < 4; ++k) {
                    remaining[k] = req[k] - remaining[k];
                }

                int suffixLength = n - i - 1;

                if (minDigits(remaining) <= suffixLength) {
                    string answer = num.substr(0, i);
                    answer.push_back(char('0' + digit));

                    answer += buildSmallest(remaining, suffixLength);
                    return answer;
                }
            }
        }

        // No valid answer of the same length: use a longer number.
        int length = max(n + 1, minDigits(req));
        return buildSmallest(req, length);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna