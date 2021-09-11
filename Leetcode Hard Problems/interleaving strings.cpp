class Solution {
public:
    int n,m,k;
    bool poss(int c1,int c2,int c3,string &s1,string &s2,string &s3)
    {
        if(c1==n && c2==m && c3==k) return true;
        if(c1==n)
        {
            return s2.substr(c2,m-c2+1)==s3.substr(c3,k-c3+1);
        }
        if(c2==m)
        {
            return s1.substr(c1,n-c1+1)==s3.substr(c3,k-c3+1);
        }
        if(s1[c1]==s3[c3] && poss(c1+1,c2,c3+1,s1,s2,s3))
        {
            return true;
        }
        if(s2[c2]==s3[c3] && poss(c1,c2+1,c3+1,s1,s2,s3)) return true;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.length(),m = s2.length(),k = s3.length();
        if(n + m != k) return false;
        if(n==0) return s2==s3;
        if(m==0) return s1==s3;
        vector<vector<int>> dp(n+1,vector<int> (m+1,false));
        dp[0][0] = true;
        for (int i=1;i<=n;i++)
        {
            if(s1[i-1]==s3[i-1]) dp[i][0] = true;
            else break;
        }
        for (int i=1;i<=m;i++)
        {
            if(s2[i-1]==s3[i-1]) dp[0][i] = true;
            else break;
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if(s3[i + j - 1] != s1[i-1] && s3[i + j - 1] != s2[j-1]) dp[i][j] = false;
                else if(s3[i + j - 1] == s1[i-1] && s3[i + j - 1] == s2[j-1])
                {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else if(s3[i + j - 1] == s1[i-1])
                {
                    dp[i][j] = dp[i-1][j];
                }
                else dp[i][j] = dp[i][j-1];
            }
        }
        return dp[n][m];

    }
};
