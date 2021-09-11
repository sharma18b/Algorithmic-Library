class Solution {
public:
    bool valid(int x,int y,int n, int m)
    {
        if(x >=0 && x < n && y >=0 && y < m) return true;
        return false;
    }
    int rec(int x,int y,vector<vector<bool>> &vis,vector<vector<int>> &dp,vector<vector<int>>& matrix,int n,int m)
    {
        if(dp[x][y]!=-1) return dp[x][y];
        int k = 1;
        vis[x][y] = true;
        if(valid(x+1,y,n,m) && !vis[x+1][y] && matrix[x+1][y] > matrix[x][y])
        {
            int l = 1 + rec(x+1,y,vis,dp,matrix,n,m);
            k = max(k,l);
        }
        if(valid(x-1,y,n,m) && !vis[x-1][y] && matrix[x-1][y] > matrix[x][y])
        {
            int l = 1 + rec(x-1,y,vis,dp,matrix,n,m);
            k = max(k,l);
        }
        if(valid(x,y+1,n,m) && !vis[x][y+1] && matrix[x][y+1] > matrix[x][y])
        {
            int l = 1 + rec(x,y+1,vis,dp,matrix,n,m);
            k = max(k,l);
        }
        if(valid(x,y-1,n,m) && !vis[x][y-1] && matrix[x][y-1] > matrix[x][y])
        {
            int l = 1 + rec(x,y-1,vis,dp,matrix,n,m);
            k = max(k,l);
        }
        vis[x][y] = false;
        dp[x][y] = k;
        return k;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 1,n = matrix.size(),m = matrix[0].size();
        if(n==1 && m==1) return 1;
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        vector<vector<int>> dp(n,vector<int> (m,-1));
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(dp[i][j]==-1)
                {
                    int p = rec(i,j,vis,dp,matrix,n,m);
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
