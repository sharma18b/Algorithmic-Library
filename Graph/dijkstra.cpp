#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int dijkstra(vector<vector<pair<int,int>>> v,int src,int n)
{
  vector<int> dist(n,INT_MAX);
  //vector<bool> vis(n,false);
  priority_queue< pii, vector <pii> , greater<pii> > pq;
  pq.push({0,src});
  dist[src] = 0;
  while (!pq.empty()) {
    pii temp = pq;
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
}
