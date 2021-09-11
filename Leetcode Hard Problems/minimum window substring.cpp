class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(),ma = t.length();
        if(n==0 || ma==0 || n < ma) return "";
        unordered_map<char,int> m;
        int count=0,minlen = INT_MAX,low=0,minstart = 0;
        for (auto i : t) {m[i]++;}
        for (int hi=0;hi<n;hi++)
        {
            if(m[s[hi]] > 0) count++;
            m[s[hi]]--;
            if(count==ma)
            {
                while(low < hi && m[s[low]] < 0) m[s[low]]++,low++;
                if(minlen > hi - low)
                {
                    minlen = hi - low + 1;
                    minstart = low;
                }
                m[s[low++]]++;
                count--;
            }
        }
        return (minlen==INT_MAX) ? "" : s.substr(minstart,minlen);
    }

};
