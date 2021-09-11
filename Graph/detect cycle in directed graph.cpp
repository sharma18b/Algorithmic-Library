bool dfs(vector<vector<int>> &adj,int curr,vector<bool> &vis,vector<int> &rec)
{
    if(vis[curr]) return true;
    vis[curr] = true;
    for (int i=0;i<adj[curr].size();i++)
    {
        if(dfs(adj,adj[curr][i],vis)) return true;
    }
    vis[curr] = false;
    return false;
}


int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A);
    vector<bool> vis(A,false);
    vector<bool> rec(A,false);
    for (int i=0;i<B.size();i++)
    {
        adj[B[i][0]-1].push_back(B[i][1]-1);
        //adj[B[i][1]-1].push_back(B[i][0]-1);
    }
    for (int i=0;i<A;i++)
    {
        if(!vis[i])
        {
            if(dfs(adj,i,vis,rec)) return 1;
        }
    }
    return 0;
}
