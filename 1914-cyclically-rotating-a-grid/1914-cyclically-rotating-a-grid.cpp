class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {

            int top = layer;
            int left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;

            // Store the current layer
            vector<int> ring;

            // Top row: left -> right
            for (int j = left; j <= right; j++)
                ring.push_back(grid[top][j]);

            // Right column: top+1 -> bottom
            for (int i = top + 1; i <= bottom; i++)
                ring.push_back(grid[i][right]);

            // Bottom row: right-1 -> left
            for (int j = right - 1; j >= left; j--)
                ring.push_back(grid[bottom][j]);

            // Left column: bottom-1 -> top+1
            for (int i = bottom - 1; i > top; i--)
                ring.push_back(grid[i][left]);

            int len = ring.size();

            // Counter-clockwise rotation
            int shift = k % len;

            vector<int> rotated(len);

            for (int i = 0; i < len; i++) {
                rotated[i] = ring[(i + shift) % len];
            }

            int idx = 0;

            // Put rotated values back

            // Top row
            for (int j = left; j <= right; j++)
                grid[top][j] = rotated[idx++];

            // Right column
            for (int i = top + 1; i <= bottom; i++)
                grid[i][right] = rotated[idx++];

            // Bottom row
            for (int j = right - 1; j >= left; j--)
                grid[bottom][j] = rotated[idx++];

            // Left column
            for (int i = bottom - 1; i > top; i--)
                grid[i][left] = rotated[idx++];
        }

        return grid;
    }
};