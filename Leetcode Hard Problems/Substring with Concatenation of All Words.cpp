class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int k = words.size();
        int wl = words[0].length();
        int awl = k*wl;
        vector<int> ans;
        if(n < awl || k==0) return ans;
        unordered_map<string,int> m;
        for (auto i : words)
            m[i]++;
        for (int i=0;i<n - k*wl + 1;i++)
        {
            int count = 0,j = i;
            unordered_map<string,int> dummy;
            while(j < i + awl)
            {
                string sub = s.substr(j,wl);
                if(m.count(sub))
                {
                    dummy[sub]++;
                    if(dummy[sub] > m[sub]) break;
                    else 
                    {
                        count++;
                        j += wl;
                    }
                }
                else break;
            }
            if(count==k) ans.push_back(i);
        }
        return ans;
    }
};