class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        if(n==0) return 0;
        int best = INT_MIN,maxi = 1,mini = 1;
        for(auto i : a)
        {
            if(i < 0)
            {
                swap(maxi,mini);
            }
            maxi = max(maxi*i,i);
            mini = min(mini*i,i);
            best = max(maxi,best);
        }
        return best;

    }
};
