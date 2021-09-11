class Solution {
public:
    bool isposs(int x,int y,int n,vector<string> v)
    {
        for (int i=0;i<n;i++)
        {
            if (v[x][i]=='Q' || v[i][y]=='Q') return false;
        }
        int i = x-1,j = y-1;
        while(i >=0 && j >=0)
        {
            if(v[i][j]=='Q') return false;
            i--;j--;
        }
        i = x-1,j = y+1;
        while(i >=0 && j < n)
        {
            if(v[i][j]=='Q') return false;
            i--;j++;
        }
        return true;
    }
    void solve(int x,int y,int curr,int n,vector<string> v,vector<vector<string>> &ans)
    {
        if(x==n && curr < n) return;
        if(x > curr) return;
        if(x==n)
        {
            ans.push_back(v);
            return;
        }
        int nexti = x,nextj = y+1;
        if(y==n-1)
        {
            nexti = x+1;
            nextj = 0;
        }
        if(isposs(x,y,n,v))
        {
            v[x][y] = 'Q';
            solve(nexti,nextj,curr+1,n,v,ans);
            v[x][y] = '.';
        }
        solve(nexti,nextj,curr,n,v,ans);
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s = "";
        for (int i=0;i<n;i++) s+= '.';
        vector<string> v;
        for (int i=0;i<n;i++) v.push_back(s);
        solve(0,0,0,n,v,ans);
        return ans;

    }
};
