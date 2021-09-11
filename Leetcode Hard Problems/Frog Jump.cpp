class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n<2) return true;
        if(stones[1]!=1) return false;
        unordered_map<long,unordered_set<int>> jumps;
        jumps[0].insert(0);
        for (long i=0;i<n;i++)
        {
            if(jumps.find(stones[i])!=jumps.end())
            {
                for (auto x : jumps[stones[i]])
                {
                    if(x-1 > 0) jumps[stones[i] + x - 1].insert(x-1);
                    jumps[stones[i] + x ].insert(x);
                    jumps[stones[i] + x + 1 ].insert(x + 1);
                }
            }
            if(i==n-1)
            {
                if(jumps.find(stones[i])!=jumps.end()) return true;
                else return false; 
            }
        }
        return false;
        
    }
};