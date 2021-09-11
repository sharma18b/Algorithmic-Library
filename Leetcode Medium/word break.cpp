class Solution {
public:
    bool dictcontains(string s,vector<string>& wordDict)
    {
        for (int i=0;i<wordDict.size();i++)
        {
            if(s==wordDict[i]) return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        if(n==0) return true;
        vector<bool> dp(n+1,false);
        for (int i=1;i<=n;i++)
        {
            if(!dp[i] && dictcontains(s.substr(0,i),wordDict))
                dp[i] = true;
            if(i==n && dp[i]) return true;
            if(dp[i])
            {
                for (int j=i;j<=n;j++)
                {
                    if(!dp[j] && dictcontains(s.substr(i,j-i),wordDict))
                        dp[j] = true;
                    if(dp[n]) return true;
                }
            }
        }
        return false;
    }
};
