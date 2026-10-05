class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {

            vector<int> ring;

            int top = layer;
            int left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;

            // Top row: left → right
            for (int j = left; j <= right; j++) {
                ring.push_back(grid[top][j]);
            }

            // Right column: top+1 → bottom
            for (int i = top + 1; i <= bottom; i++) {
                ring.push_back(grid[i][right]);
            }

            // Bottom row: right-1 → left
            for (int j = right - 1; j >= left; j--) {
                ring.push_back(grid[bottom][j]);
            }

            // Left column: bottom-1 → top+1
            for (int i = bottom - 1; i > top; i--) {
                ring.push_back(grid[i][left]);
            }

            // Number of rotations
            int len = ring.size();
            int rotations = k % len;

            // Counter-clockwise rotation
            rotate(ring.begin(), ring.begin() + rotations, ring.end());

            int index = 0;

            // Put values back

            // Top row
            for (int j = left; j <= right; j++) {
                grid[top][j] = ring[index++];
            }

            // Right column
            for (int i = top + 1; i <= bottom; i++) {
                grid[i][right] = ring[index++];
            }

            // Bottom row
            for (int j = right - 1; j >= left; j--) {
                grid[bottom][j] = ring[index++];
            }

            // Left column
            for (int i = bottom - 1; i > top; i--) {
                grid[i][left] = ring[index++];
            }
        }

        return grid;
    }
};