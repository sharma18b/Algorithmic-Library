class Solution {
public:
    void rec(vector<string> &res,vector<string> a,int i,string s,string dig)
    {
        if(i==dig.size())
        {
            res.push_back(s);
            return;
        }
        for(auto j : a[int(dig[i]) - (int)'0'])
        {
            string temp = s;
            temp += j;
            rec(res,a,i+1,temp,dig);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0) return res;
        vector<string> a = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        rec(res,a,0,"",digits);
        return res;
    }
};
