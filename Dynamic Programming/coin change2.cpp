int Solution::coinchange2(vector<int> &A, int B) {
    vector<int> dp(B+1,0);
    int n = A.size(),mod = 1000007;
    dp[0] = 1;
    for (int i=0;i<n;i++)
    {
        for (int j = A[i];j<=B;j++)
        dp[j] = dp[j]%mod + dp[j-A[i]]%mod;
    }
    return dp[B]%mod;
}
