class Solution {
public:
    bool isvalid(int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j<m && j>=0) return true;
        return false;
    }
    void bfs(vector<vector<char>>& grid,vector<vector<bool>> &v,int i,int j,int n,int m){
        v[i][j] = true;
        if(isvalid(i+1,j,n,m) && !v[i+1][j] && grid[i+1][j]=='1') bfs(grid,v,i+1,j,n,m);
        if(isvalid(i-1,j,n,m) && !v[i-1][j] && grid[i-1][j]=='1') bfs(grid,v,i-1,j,n,m);
        if(isvalid(i,j+1,n,m) && !v[i][j+1] && grid[i][j+1]=='1') bfs(grid,v,i,j+1,n,m);
        if(isvalid(i,j-1,n,m) && !v[i][j-1] && grid[i][j-1]=='1') bfs(grid,v,i,j-1,n,m);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> v(n,vector<bool> (m,false));
        int z = 0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !v[i][j]) z++,bfs(grid,v,i,j,n,m);
            }
        }
        return z;
    }
};
