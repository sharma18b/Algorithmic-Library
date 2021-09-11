class Solution {
public:
    bool valid(int x,int y,int n,int m)
    {
        if(x>=0 && y>=0 && x < n && y < m) return true;
        return false;
    }
    bool rec(int curr,int x,int y, vector<vector<char>>& board,string &s,vector<vector<bool >> &vis,int n,int m)
    {
        if(curr==s.length()-1) return true;
        vis[x][y] = true;
        if(valid(x+1,y,n,m) && !vis[x+1][y] && board[x+1][y]==s[curr+1])
        {
            if(rec(curr+1,x+1,y,board,s,vis,n,m)) return true;
        }
        if(valid(x-1,y,n,m) && !vis[x-1][y] && board[x-1][y]==s[curr+1])
        {
            if(rec(curr+1,x-1,y,board,s,vis,n,m)) return true;
        }
        if(valid(x,y+1,n,m) && !vis[x][y+1] && board[x][y+1]==s[curr+1])
        {
            if(rec(curr+1,x,y+1,board,s,vis,n,m)) return true;
        }
        if(valid(x,y-1,n,m) && !vis[x][y-1] && board[x][y-1]==s[curr+1])
        {
            if(rec(curr+1,x,y-1,board,s,vis,n,m)) return true;
        }
        vis[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string s) {
        int n= board.size();
        int m = board[0].size();
        int ns = s.length();
        if(ns==0) return false;
        vector<vector<bool >> vis(n,vector<bool> (m,false));
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(board[i][j]==s[0])
                {
                    //vector<vector<bool >> vis(n,vector<bool> (m,false));
                    if(rec(0,i,j,board,s,vis,n,m)) return true;
                }
            }
        }
        return false;

    }
};
