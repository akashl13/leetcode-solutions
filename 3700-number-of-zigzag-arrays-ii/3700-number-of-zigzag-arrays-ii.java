
class Solution {
    static final long MOD = 1000000007L;

    public int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int size = 2 * m;

        long[][] mat = new long[size][size];

        for (int v = 0; v < m; v++) {
            for (int u = 0; u < v; u++) {
                mat[v][m + u] = 1;
            }

            for (int u = v + 1; u < m; u++) {
                mat[m + v][u] = 1;
            }
        }

        long[] dp = new long[size];

        for (int v = 0; v < m; v++) {
            dp[v] = v;
            dp[m + v] = m - 1 - v;
        }

        long[][] result = matrixPower(mat, n - 2);
        long[] finalDP = multiply(result, dp);

        long ans = 0;

        for (int i = 0; i < size; i++) {
            ans = (ans + finalDP[i]) % MOD;
        }

        return (int) ans;
    }

    private long[][] matrixPower(long[][] mat, int power) {
        int n = mat.length;

        long[][] result = new long[n][n];

        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
        }

        while (power > 0) {
            if ((power & 1) == 1) {
                result = matrixMultiply(result, mat);
            }

            mat = matrixMultiply(mat, mat);
            power >>= 1;
        }

        return result;
    }

    private long[][] matrixMultiply(long[][] a, long[][] b) {
        int n = a.length;
        long[][] c = new long[n][n];

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (a[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    c[i][j] = (
                        c[i][j] + a[i][k] * b[k][j]
                    ) % MOD;
                }
            }
        }

        return c;
    }

    private long[] multiply(long[][] mat, long[] dp) {
        int n = dp.length;
        long[] result = new long[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i] = (
                    result[i] + mat[i][j] * dp[j]
                ) % MOD;
            }
        }

        return result;
    }
}
