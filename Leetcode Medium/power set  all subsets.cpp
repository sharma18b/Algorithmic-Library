class Solution {
public:
    void rec(int curr,vector<int> cv,set<vector<int>> &s,vector<int> &a)
    {
        if(curr==a.size())
        {
            if(s.find(cv)==s.end()) s.insert(cv);
            return;
        }
        vector<int> temp = cv;
        temp.push_back(a[curr]);
        rec(curr+1,temp,s,a);
        rec(curr+1,cv,s,a);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        //ans.push_back(vector<int> ());
        set<vector<int>> s;
        rec(0,vector<int>(),s,nums);
        for(auto i : s) ans.push_back(i);
        return ans;
    }
};
