

#define pii pair<int,int>

int dijkstra(vector<vector<pair<int,int>>> v,int src,int n,int dest)
{
  vector<int> dist(n,INT_MAX);
  //vector<bool> vis(n,false);
  priority_queue< pii, vector <pii> , greater<pii> > pq;
  pq.push({0,src});
  dist[src] = 0;
  while (!pq.empty()) {
    pii temp = pq.top();
    int curr = temp.second;
    pq.pop();
    for (int i=0;i<v[curr].size();i++)
    {
      int x = v[curr][i].first;
      int w = v[curr][i].second;
      if(dist[x] > dist[curr] + w)
      {
        dist[x] = dist[curr] + w;
        pq.push({dist[x],x});
      }
    }
    /* code */
  }
  return dist[dest];
}


int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    vector<vector<pair<int,int>>> adj(A);
    for (int i=0;i<B.size();i++)
    {
        adj[B[i][0]-1].push_back({B[i][1]-1,B[i][2]});
    }
    // set<pair<int,int>> s;
    // s.insert({C-1,0});
    // while(!s.empty())
    // {

    // }
    int ans = INT_MAX;
    for (int i=0;i<E.size();i++)
    {
         if(E[i][0] > A || E[i][1] > A) continue;
         adj[E[i][0]-1].push_back({E[i][1]-1,E[i][2]});
         adj[E[i][1]-1].push_back({E[i][0]-1,E[i][2]});
         ans = min(ans,dijkstra(adj,C-1,A,D-1));
         adj[E[i][0]-1].pop_back();
         adj[E[i][1]-1].pop_back();
    }
    return ans==INT_MAX ? -1:ans;



}

// #define pii pair<int,int>

// int dijkstras(int src, int dest, int n, vector<vector<pii>> &adj){
//     vector<int> dist(n+1, INT_MAX);
//     vector<bool> vis(n+1, false);
//     dist[src]=0;
//     priority_queue<pii, vector<pii>, greater<pii>> minHp;
//     minHp.push({0,src});

//     while(!minHp.empty()){
//         pii p=minHp.top();
//         int u=p.second;
//         minHp.pop();
//         if(vis[u]) continue;
//         vis[u]=true;

//         for(auto child:adj[u]){
//             int v=child.first;
//             int w=child.second;
//             if(dist[v]>dist[u]+w){
//                 dist[v]=dist[u]+w;
//                 minHp.push({dist[v], v});
//             }
//         }
//     }
//     return dist[dest];
// }

// int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
//     vector<vector<pii>> adj(A+1);
//     for(auto v:B){
//         adj[v[0]].push_back({v[1], v[2]});
//     }

//     int ans=INT_MAX;
//     // take one edge at a time from E
//     for(auto v:E){
//       if(v[0]>A || v[1]>A) continue;

//         adj[v[0]].push_back({v[1], v[2]});
//         adj[v[1]].push_back({v[0], v[2]});
//         int temp=dijkstras(C,D,A,adj);
//         ans=min(ans, temp);
//         adj[v[0]].pop_back();
//         adj[v[1]].pop_back();

//     }
//     return (ans==INT_MAX) ? -1 : ans;
// }
