class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> count;
        for (auto i : nums)
        {
            count[i]++;
        }
        int avoid = 0,take = 0,prev = -1,p;
        for (auto i : count)
        {
            if(i.first - 1 != prev) 
            {
                p = take;
                take = max(avoid,take) + i.first * i.second;
                avoid = max(avoid,p);
            }
            else 
            {
                p = take;
                take = avoid + i.first * i.second;
                avoid = max(avoid , p);
            }
            prev = i.first;
        }
        return max(avoid,take);
    }
};