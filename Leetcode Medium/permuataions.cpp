class Solution {
public:
    void rec(set<vector<int>> s,vector<vector<int>> &ans,vector<int> curr,vector<bool> vis,vector<int> &a,int n)
    {
        if(curr.size() == n-1)
        {
            for(int i=0;i<n;i++) if(!vis[i]) curr.push_back(a[i]);
            if(s.find(curr)==s.end())
            {
                ans.push_back(curr);
            }
            return;
        }
        for (int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i] = true;
                vector<int> temp = curr;
                temp.push_back(a[i]);
                rec(s,ans,temp,vis,a,n);
                vis[i] = false;
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<bool> vis(n,false);
        rec(s,ans,vector<int> (),vis,nums,n);
        return ans;
    }
};
