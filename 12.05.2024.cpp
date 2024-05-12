class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
            int n = grid.size();
    std::vector<std::vector<int>> maxLocal(n - 2, std::vector<int>(n - 2, 0));

    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            int maxVal = grid[i - 1][j - 1];
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    maxVal = std::max(maxVal, grid[x][y]);
                }
            }
            maxLocal[i - 1][j - 1] = maxVal;
        }
    }

    return maxLocal;
}
        

};
