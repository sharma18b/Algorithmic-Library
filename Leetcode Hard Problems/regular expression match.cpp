class Solution {
public:
    bool isMatch(string s, string p) {
      // this solution dows not work on leetcode but works everyehere else
      // works for wildcard matching geeks4geeks
      // interviewbit etc

        int n = s.length();
        int m = p.length();
        if(n==0) return m==0;
        bool dp[n+1][m+1];
        memset(dp,false,sizeof(dp));
        dp[0][0] = true;
        for (int j=1;j<=m;j++)
        {
            if(p[j-1]=='*') dp[0][j] = dp[0][j-1];
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if(p[j-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else if(s[i-1]==p[j-1] || p[j-1]=='.') dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[n][m];

    }
};
