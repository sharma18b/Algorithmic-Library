void dfs(vector<bool> &vis,int curr,vector<vector<int>> &adj,vector<int> &dist)
{
    vis[curr] = true;
    for (int i=0;i<adj[curr].size();i++)
    {
        if(!vis[adj[curr][i]])
        {
            dist[adj[curr][i]] = min(dist[curr] + 1 , dist[adj[curr][i]]);
            dfs(vis,adj[curr][i],adj,dist);
        }
    }
}



int Solution::solve(vector<int> &A) {
    // vector<int> hgt(A.size(),0);
    // int ans=0,maxx=0;
    // for(int i=A.size()-1;i>0;i--){
    //     ans=max(ans,hgt[A[i]]+hgt[i]+1);
    //     hgt[A[i]]=max(hgt[i]+1,hgt[A[i]]);
    // }
    // return ans;
    int n = A.size(),root;
    vector<int> dist(n,INT_MAX);
    vector<bool> vis(n,false);
    vector<vector<int>> adj(n);
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=-1){
        adj[i].push_back(A[i]);
        adj[A[i]].push_back(i);
        }
        else root = i;
    }
    dist[root] = 0;
    dfs(vis,root,adj,dist);
    int mindistidx = root;
    for (int i=0;i<n;i++)
    {
        if(dist[i] > dist[mindistidx])
        {
            mindistidx = i;
        }
    }
    for (int i=0;i<n;i++) vis[i] = false,dist[i] = INT_MAX;
    dist[mindistidx] = 0;
    dfs(vis,mindistidx,adj,dist);
    int ans = 0;
    for (int i=0;i<n;i++)
    {
        ans = max(ans,dist[i]);
    }
    return ans;

}
