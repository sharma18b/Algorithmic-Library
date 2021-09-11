class Solution {
public:
    bool val(string k)
    {
        int z = 0;
        for (auto i : k)
        {
            z += (i=='(') ? 1 : ((i!=')') ? 0 : -1);
            if(z < 0) return false;
        }
        if(z == 0) return true;
        else return false;
    }


    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        vector<string> ans;
        queue<string > q;
        q.push(s);
        set<string> myset;
        myset.insert(s);
        bool all_strings_of_this_level = false;
        while(!q.empty())
        {
            string k = q.front();
            q.pop();
            if(val(k))
            {
                ans.push_back(k);
                all_strings_of_this_level = true;
            }
            if(all_strings_of_this_level) continue;
            for (int i=0;i<k.length();i++)
            {
                if(k[i]!='(' && k[i]!=')') continue;
                else
                {
                    string p = k.substr(0,i) + k.substr(i+1);
                    if (myset.find(p)==myset.end()){
                       q.push(p);
                        myset.insert(p);
                    }
                }
            }
        }
        return ans;
    }
};
