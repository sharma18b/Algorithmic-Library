class Solution {
public:
    int count(string s,string z)
    {
        if(z.length()==0) return s.length();
        int n = s.length(),cnt =0,j = 0,m = z.length();
        for (int i=0;i<n;i++)
        {
            if(s[i]==z[j])
            {
                j++;
                if(j==m) j=0,cnt++;
            }
        }
        return cnt;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> q;
        string anss = "";
        q.push("");
        int ans = 0,n = s.length();
        while(!q.empty())
        {
            string x = q.front();
            q.pop();
            int p = count(s,x);
            if (p >=k )
            {
                if (x.length() >= ans )
                {
                    ans = x.length();
                    anss = x;
                }
                for (char g = 'a';g <= 'z';g++)
                {
                    string ne = x;
                    ne+=g;
                    q.push(ne);
                }
            }
        } 
        return anss;
    }
};