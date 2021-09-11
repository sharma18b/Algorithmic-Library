class Solution {
public:
    void rec(vector<string> &ans,string s,set<string> &u,int sp,int ep,int curr,int n)
    {
        if(curr == 2*n - 1)
        {
            s += ')';
            ans.push_back(s);
            return;
        }
        if(sp > n || ep > n || ep > sp) return;
        string temp = s;
        if(sp < n)
        {
            s += '(';
            rec(ans,s,u,sp+1,ep,curr+1,n);
        }
        if(ep < sp)
        {
            temp += ')';
            rec(ans,temp,u,sp,ep+1,curr+1,n);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        set<string> u;
        rec(ans,s,u,0,0,0,n);
        return ans;
    }
};
