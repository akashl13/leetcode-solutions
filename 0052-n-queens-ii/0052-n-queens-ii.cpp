
class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        return backtrack(0, n, col, diag1, diag2);
    }

    int backtrack(int row, int n,
                  vector<bool>& col,
                  vector<bool>& diag1,
                  vector<bool>& diag2) {
        if (row == n) {
            return 1;
        }

        int count = 0;

        for (int c = 0; c < n; c++) {
            int d1 = row - c + n - 1;
            int d2 = row + c;

            if (col[c] || diag1[d1] || diag2[d2]) {
                continue;
            }

            col[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            count += backtrack(row + 1, n, col, diag1, diag2);

            col[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }

        return count;
    }
};