

class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        
        // dp[i][j][k] represents the number of valid sequences of length i
        // with j absences (0 or 1) and k consecutive lates (0, 1, 2)
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        // Base case: length 0, one valid sequence (empty sequence)
        dp[0][0][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) { // j: number of 'A's
                for (int k = 0; k < 3; ++k) { // k: number of consecutive 'L's
                    
                    // Add 'P': does not change the number of 'A's or consecutive 'L's
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
                    
                    // Add 'A': can only add 'A' if there were no 'A's in the previous sequence
                    if (j > 0) {
                        dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j - 1][k]) % MOD;
                    }
                    
                    // Add 'L': can only add 'L' if there were less than 2 consecutive 'L's
                    if (k > 0) {
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                    }
                }
            }
        }
        
        // Sum all valid sequences of length n
        int result = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                result = (result + dp[n][j][k]) % MOD;
            }
        }
        
        return result;
    }
};
