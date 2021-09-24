typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

class Solution {
public:
    int dijkstra(int src,int dst,vector<vector<pll>> &adj)
    {
        int n = adj.size();
        vector<LL> dis(n,1e12);
        dis[0] = 0;
        vector<LL> ways(n,0);
        ways[0] = 1;
        int mod = 1e9 + 7;
        priority_queue<pll,vector<pll>,greater<>> pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto [d,u] = pq.top();pq.pop();
            if(dis[u] < d) continue;
            for (auto [v,time] : adj[u])
            {
                if(dis[v] > d + time)
                {
                    dis[v] = d + time;
                    ways[v] = ways[u];
                    pq.push({dis[v],v});
                }
                else if (dis[v] == d + time)
                {
                    ways[v] = (ways[v] + ways[u])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> adj(n);
        for (auto i : roads)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        return dijkstra(0,n-1,adj);
        //return ans;
        
    }
};