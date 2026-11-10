class Solution {
public:
    static const long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] +
                               A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix A, long long p) {
        int n = A.size();

        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (p > 0) {
            if (p & 1)
                res = multiply(res, A);

            A = multiply(A, A);
            p >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        /*
            State:

            0 ... m-1
            = last move was increasing

            m ... 2m-1
            = last move was decreasing
        */

        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        // Increasing -> decreasing
        // If previous value is y and current value is x:
        // y > x
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < y; x++) {
                T[m + x][y] = 1;
            }
        }

        // Decreasing -> increasing
        // Previous value is y and current value is x:
        // y < x
        for (int y = 0; y < m; y++) {
            for (int x = y + 1; x < m; x++) {
                T[x][m + y] = 1;
            }
        }

        // Initial states for arrays of length 2.
        vector<long long> initial(S, 0);

        for (int x = 0; x < m; x++) {
            // Previous value < x
            initial[x] = x;

            // Previous value > x
            initial[m + x] = m - 1 - x;
        }

        // We already have length 2.
        // Need n-2 transitions.
        Matrix P = power(T, n - 2);

        vector<long long> finalState(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                finalState[i] =
                    (finalState[i] +
                     P[i][j] * initial[j]) % MOD;
            }
        }

        long long ans = 0;

        for (long long x : finalState) {
            ans = (ans + x) % MOD;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna