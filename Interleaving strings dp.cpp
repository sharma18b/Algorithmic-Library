// is C made of character from A&B
bool isinterleaved(string A,string B,string C)
{
    int n = A.length();
    int m = B.length();
    vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
    // int dp[n+1][m+1];
    // memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {

            if (i==0 && j==0) dp[i][j] = true;
            else if (j==0)
            {
                if (A[i-1]==C[i-1]) dp[i][j] = dp[i-1][j];
            }
            else if (i==0)
            {
                if (B[j-1]==C[j-1]) dp[i][j] = dp[i][j-1];
            }
            else if ((A[i-1] == C[i+j-1]) && (B[j-1] != C[i+j-1])) dp[i][j] = dp[i-1][j];
            else if ((A[i-1] != C[i+j-1]) && (B[j-1] == C[i+j-1])) dp[i][j] = dp[i][j-1];
            else if ((A[i-1] == C[i+j-1]) && (B[j-1] == C[i+j-1])) dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
        }
    }
        return dp[n][m];
}
