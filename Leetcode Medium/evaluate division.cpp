class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       unordered_map<string,vector<pair<string,double>>> adj;
        for (int i=0;i<equations.size();i++)
        {
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        int n = queries.size();
        vector<double> ans(n,-1);
        for (int i=0;i<n;i++)
        {
            if(adj.find(queries[i][0])==adj.end() || adj.find(queries[i][1])==adj.end()) continue;
            else
            {
                queue<pair<string,double>> q;
                q.push({queries[i][0],1});
                string denom = queries[i][1];
                bool found = false;
                set<string> vis;
                while(!q.empty() && !found)
                {
                    int m = q.size();
                    while(m-- && !found)
                    {
                        auto x = q.front();
                        q.pop();
                        string s = x.first;
                        double curr = x.second;
                        for (auto p : adj[s])
                        {
                            if(vis.find(p.first)==vis.end())
                            {
                                if(p.first==denom)
                                {
                                    found = true;
                                    ans[i] = curr*p.second;
                                    break;
                                }
                                else
                                {
                                    q.push({p.first,curr*p.second});
                                    vis.insert(p.first);
                                }
                            }
                        }
                    }
                }
            }


        }
        return ans;
    }
};
