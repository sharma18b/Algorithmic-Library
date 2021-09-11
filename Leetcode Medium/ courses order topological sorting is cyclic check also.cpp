class Solution {
public:
    void dfs(int x,vector<vector<int>> &adj,vector<bool> &vis,stack<int> &s){
        vis[x] = true;
        for (auto i : adj[x])
        {
            if(!vis[i]) dfs(i,adj,vis,s);
        }
        s.push(x);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> ans;
        stack<int> s;
        vector<bool> vis(numCourses,false);
        vector<bool> exp(numCourses,false);
        for (int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,s);
            }
        }
        unordered_map<int,int> m;int ind=0;
        while(!s.empty())
        {
            m[s.top()] = ind++;
            ans.push_back(s.top());
            s.pop();
        }
        for (auto i : ans)
        {
            for (auto j : adj[i])
            {
                if(m[i] > m[j]) return vector<int>();
            }
        }
        return ans;
    }
};
