#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;


void dfs(int v,int p)
{
    tin[v] = timer++;
    up[v][0] = p;

}


void preprocess(int root)
{
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = (ceil(log2(n)));
    up = vector<vector<int>> (n,vector<int> (l+1));
    dfs(1,1);
}
int main()
{
    
    cin >> n >> m;
    adj.resize(n+1);
    for (int i=0;i<m;i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    preprocess(1);
    cout << lca(1,2) << endl; 



}