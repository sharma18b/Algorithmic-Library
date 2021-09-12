# define MOD 1000000007
int Solution::solve(int A, int B) {
    // corner case
    if (B == 0) {
        return 1;
    }

    vector<int>digits {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    /*
        Two Dimensional DP
            dp[i][j]:
                * i -> number of digits used so far
                * j -> sum made so far
    */
    vector<vector<int>>dp(A + 1, vector<int>(B + 1, 0));

    // there's atleast 1 way to make sum equal to these digits
    for(int i : digits) {
        if(i <= B) {
            dp[1][i] = 1;
        }
    }
    for(int i = 0; i < A; i++) {
        for(int j = 0; j < B; j++) {
            for(int k : digits) {
                if (i != 0 || k != 0) {
                    if (j + k <= B) {
                        dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j]) % MOD;
                    }
                }
            }
        }
    }
    return dp[A][B];
}
