class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(),m = word2.length();
        if(n==0) return m;
        if(m==0) return n;
        //if(n==0 && m==0) return 0;
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for (int i=0;i<=n;i++)
        {
            for (int j=0;j<=m;j++)
            {
                if(i==0 || j==0) dp[i][j] = i+j;
                else
                {
                    if(word1[i-1]==word2[j-1])
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
                }
            }
        }
        return dp[n][m];

    }
};
