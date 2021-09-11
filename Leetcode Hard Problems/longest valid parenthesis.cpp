class Solution {
public:
    int longestValidParentheses(string a) {
        int n =a.length();
        if (n==0) return 0;
        stack<int> s;s.push(-1);
        int maxi = 0,curr =0;
        for (int i=0;i<n;i++)
        {
            if(a[i]=='(') s.push(i);
            else
            {
                if(!s.empty()){
                    s.pop();
                }
                if(!s.empty())
                {
                    maxi = max(maxi,i - s.top());
                }
                else s.push(i);
            }
        }
        return maxi;
        (())((()))
    }
};
