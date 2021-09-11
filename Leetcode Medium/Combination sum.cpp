class Solution {
public:
    void rec(int curr,int currsum,vector<vector<int>>&ans,vector<int> cv,int target,vector<int> &a,set<vector<int>> &s)
    {
        if(currsum==target)
        {
            if(s.find(cv)==s.end())
            {
                s.insert(cv);
                ans.push_back(cv);
            }
            return;
        }
        if(curr == a.size() ||  currsum > target) return;
        if(currsum + a[curr] <= target)
        {
                vector<int> temp = cv;
                temp.push_back(a[curr]);
                rec(curr,currsum + a[curr],ans,temp,target,a,s);
                rec(curr+1,currsum + a[curr],ans,temp,target,a,s);
                rec(curr+1,currsum,ans,cv,target,a,s);
        }

        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        rec(0,0,ans,vector<int>(),target,candidates,s);
        return ans;

    }
};
