class Solution {
public:
    bool isposs(int x,int y,char z,vector<vector<char>> v)
    {
        for (int i=0;i<9;i++)
        {
            if(v[i][y]==z || v[x][i]==z) return false;
        }
        int p = x/3,q = y/3;
        for (int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(v[p*3+i][q*3+j]==z) return false;
            }
        }
        return true;
    }
    void solve(int x,int y,vector<vector<char >> curr,vector<vector<char>>& board,bool &solved,int p)
    {
        if(solved==true) return;
        if(x==9 && p > 0) return;
        if(x==9 || p==0)
        {
            board = curr;
            solved = true;
            return;
        }
        int ni = x,nj = y+1;
        if(y==8)
        {
            ni = x+1,nj =0;
        }
        if(curr[x][y]!='.')
        {
            solve(ni,nj,curr,board,solved,p);
        }
        else
        {
            for (char z = '1';z<='9';z++)
            {
                if(isposs(x,y,z,curr))
                {
                    curr[x][y] = z;
                    solve(ni,nj,curr,board,solved,p-1);
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool solved = false;
        int p = 0;
        vector<vector<char >> curr = board;
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                if(board[i][j]=='.') p++;
            }
        }
        solve(0,0,curr,board,solved,p);
    }
};
