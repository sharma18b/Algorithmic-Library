int Solution::solve(vector<int> &A) {
    int n = A.size();
    int sum =0;
    for (int i=0;i<n;i++) sum+=A[i];
    vector<vector<bool>> dp(n+1,vector<bool> (sum+1,false));
    for (int i=0;i<=n;i++)
    {
        dp[i][0] = true;
    }
    for (int i=1;i<=sum;i++)
    {
        dp[0][i] = false;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=sum;j++)
        {
            if(j  < A[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j - A[i-1]];
        }
    }
    int ans =0;
    for (int i = sum/2 ;i>=0;i--)
    {
        if(dp[n][i])
        {
            ans = sum - 2*i;
            break;
        }
    }
    return ans;
}
