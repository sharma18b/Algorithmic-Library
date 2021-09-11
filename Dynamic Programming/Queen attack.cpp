vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int n  = A.size(),m = A[0].size();
    vector<vector<int>> res(n,vector<int> (m,0));
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (8,0)));
    //  top to bottom

    for (int i=1;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if(A[i-1][j]=='1') dp[i][j][0] =  1;
            else dp[i][j][0] = dp[i-1][j][0];
            if(A[n-i][j]=='1') dp[n - i - 1][j][4] = 1;
            else dp[n-i-1][j][4] = dp[n-i][j][4];
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=1;j<m;j++)
        {
            if(A[i][j-1]=='1') dp[i][j][6] =  1;
            else dp[i][j][6] = dp[i][j-1][6];
            if(A[i][m-j]=='1') dp[i][m - j - 1][2] = 1;
            else dp[i][m - j - 1][2] = dp[i][m-j][2];
        }
    }

    for (int i=1;i<n;i++)
    {
        for (int j=1;j<m;j++)
        {
            if(A[i-1][j-1]=='1') dp[i][j][7] =  1;
            else dp[i][j][7] = dp[i-1][j-1][7];
            if(A[n-i][m-j]=='1') dp[n-i-1][m - j - 1][3] = 1;
            else dp[n-i-1][m - j - 1][3] = dp[n-i][m-j][3];
        }
    }

    for (int i=n - 2;i>=0;i--)
    {
        for (int j=1;j<m;j++)
        {
            if(A[i+1][j-1]=='1') dp[i][j][5] =  1;
            else dp[i][j][5] = dp[i+1][j-1][5];
            if(A[n-i-2][m-j]=='1') dp[n-i-1][m - j - 1][1] = 1;
            else dp[n-i-1][m - j - 1][1] = dp[n-i-2][m-j][1];
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            for (int k=0;k<8;k++)
            {
                res[i][j] += dp[i][j][k];
            }
        }
    }
    return res;
}
